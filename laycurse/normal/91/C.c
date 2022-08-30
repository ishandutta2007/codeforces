#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define M 1000000009

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int main(){
  int i,j,k,l,m,n;
  int ind[110000];
  int res;

  while(scanf("%d%d",&n,&m)==2){
    unionInit(ind,n);
    res = 1;
    while(m--){
      scanf("%d%d",&i,&j); i--; j--;
      if(unionConnect(ind,i,j)==0) res = (res*2)%M;
      printf("%d\n",(res+M-1)%M);
    }
  }

  return 0;
}