#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int mem[1<<24];
int next[1<<24];
int x[32];
int y[32];
int dist[32][32];

int f(int m){
    if(mem[m]>=0)return mem[m];
    int k=-1,i;
    for(i=0;k==-1;++i){
        if(m&(1<<i))k=i;
    }
    mem[m]=2*dist[k][n]+f(m^(1<<k));
    next[m]=n;
    for(i=k+1;i<n;++i){
        if(m&(1<<i)){
            int q=dist[k][n]+dist[i][n]+dist[k][i]+f((m^(1<<k))^(1<<i));
            if(mem[m]>q){
                mem[m]=q;
                next[m]=i;
            }
        }
    }
    return mem[m];
}

void printpath(){
    int m=(1<<n)-1;
    printf("0");
    while(m!=0){
        int k=-1,i;
        for(i=0;k==-1;++i){
            if(m&(1<<i))k=i;
        }
        printf(" %d",k+1);
        if(next[m]!=n){
            printf(" %d",next[m]+1);
            m=(m^(1<<k))^(1<<next[m]);
        }
        else{
            m=(m^(1<<k));
        }
        printf(" 0");
    }
    putchar('\n');
}

int main(){
    int sx,sy,i,j;
    memset(mem,-1,sizeof(mem));
    scanf("%d %d",&sx,&sy);
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d %d",x+i,y+i);
        x[i]-=sx;
        y[i]-=sy;
    }
    for(i=0;i<n;++i){
        dist[i][n]=x[i]*x[i]+y[i]*y[i];
        for(j=0;j<n;++j){
            dist[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
        }
    }
    mem[0]=0;
    printf("%d\n",f((1<<n)-1));
    printpath();
    return 0;
}