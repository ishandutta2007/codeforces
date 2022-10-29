#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN (1<<17)
using namespace std;


// Busca T en S
char S[MAXN],T[MAXN],W[MAXN],IS[MAXN];
int ns,nt;
int table[MAXN];

int ft[MAXN],ft2[MAXN];

void fill_table(char *T, int nt){
    int pos=2,cnd=0;
    table[0]=-1;
    table[1]=0;
    while(pos<nt){
        if(T[pos-1]==T[cnd])
            table[pos++]=++cnd;
        else if(cnd>0)
            cnd=table[cnd];
        else
            table[pos++]=0;
    }
}

void kmp(char *S,int ns,char *T,int nt,int *ft){
    fill_table(T,nt);
    int m=0,i=0;memset(ft,-1,sizeof(int)*(nt+1));
    while(m+i<ns){
        if(T[i]==S[m+i]){
            i++;
            if(ft[i]==-1)ft[i]=m+i-1;
            if(i==nt){
                return;
            }
        }
        else {
            m=m+i-table[i];
            if(table[i]>-1)
                i=table[i];
            else
                i=0;
        }
    }
}

int main(){
    gets(S);ns=strlen(S);
    for(int i=0;i<ns;++i){
        IS[i]=S[ns-i-1];
    }
    int m,r=0;
    scanf("%d",&m);gets(T);
    while(m--){
        gets(T);nt=strlen(T);
        kmp(S,ns,T,nt,ft);
        //for(int i=1;i<=nt;++i)printf("%d ",ft[i]);puts("");
        for(int i=0;i<nt/2;++i){
            char t=T[i];
            T[i]=T[nt-i-1];
            T[nt-i-1]=t;
        }
        kmp(IS,ns,T,nt,ft2);
        //for(int i=1;i<=nt;++i)printf("%d ",ft2[i]);puts("");
        int q=0;
        for(int i=1;!q&&i<nt;++i){
            if(ft[i]!=-1&&ft2[nt-i]!=-1&&ft[i]<ns-ft2[nt-i]-1)q=1;
            //if(q)printf("%d %d %d\n",i,ft[i],ft2[nt-i]);
        }//if(q)puts("y");else puts("n");
        r+=q;
    }
    printf("%d\n",r);
    return 0;
}