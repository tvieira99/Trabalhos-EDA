#include<stdio.h>
#include<stdlib.h>
struct no{
/* Criando o struct "no" que contem as informacoes de cada registro,assim como o endereco
do proximo registro na pilha.*/
    int cpfc,cpft,valor;
    char op;
    struct no* prox;
};
typedef struct no reg;
struct pilha{
/* Criando o struct "pilha" que guarda o endereco do ultimo registro adicionado
    referente ao guiche escolhido.*/
    reg* topo;
};
typedef struct pilha guiche;
reg* create_guiche(){
/*Criando efetivamente um guiche atraves de ums variavel auxiliar.O endereco da
memoria criada sera enviado para aux e o topo do cuiche nao apontara para nada.
Essa funcao retorna o endereco criado.*/
    guiche* aux;
    aux=malloc(sizeof(guiche));
    aux->topo=NULL;
    return aux;
}
reg* create_reg(guiche* gn){
/*Criando efetivamente um registro atraves de ums variavel auxiliar.O endereco da
memoria criada sera enviado para aux,que fara com que a nova memoria aponte para
o ropo da pilha.Essa funcao retorna o endereco da memoria criada.*/
    reg* aux;
    aux=malloc(sizeof(reg));
    aux->prox=gn->topo;
    return aux;
}
void show_all(guiche* gn){
    if(gn->topo!=NULL){
        reg* aux;
        aux=gn->topo;
        while(aux->prox!=NULL){
            printf("[%d, %d, %c, %d]\n",aux->cpfc,aux->cpft,aux->op,aux->valor);
            aux=aux->prox;
        }
        printf("[%d, %d, %c, %d]\n",aux->cpfc,aux->cpft,aux->op,aux->valor);
    }
}
void delete_all(guiche* gn){
    reg* aux;
    while(gn->topo!=NULL){
          aux=(gn->topo)->prox;
    free(gn->topo);
    gn->topo=aux;
    }
    free(gn);
}
int main(){
/*declarando as variaveis que iremos precisar:N indicara a quantidade de registros,
v sera o vetor que apontara para cada guiche e o resto para o scanf dos dados do
registro.*/
    int n,scpfc,scpft,svalor;
    char sop;
    guiche* v[3];
/*Criando os 3 guiches e fazendo v apontar para cada um dos guiches*/
    for(int i=0;i<3;i++)
        v[i]=create_guiche();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %c %d",&scpfc,&scpft,&sop,&svalor);
        v[i%3]->topo=create_reg(v[i%3]);
        (v[i%3]->topo)->cpfc=scpfc;
        (v[i%3]->topo)->cpft=scpft;
        (v[i%3]->topo)->op=sop;
        (v[i%3]->topo)->valor=svalor;
    }
    printf("-:| RELATÓRIO PARCIAL |:-\n3\n");
    for(int i=0;i<3;i++){
        printf("guiche %d\n",i+1);
        show_all(v[i]);
    }
    for(int i=0;i<n;i++)
        delete_all(&v[i]);
return 0;
}
