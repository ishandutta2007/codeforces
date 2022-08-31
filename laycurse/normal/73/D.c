#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int ind[1000000], num[1000000];

int main(){
  int i,j,k,l,m,n;
  int N, sum, res;

  while(scanf("%d%d%d",&n,&m,&k)==3){
    unionInit(ind,n);
    while(m--){
      scanf("%d%d",&i,&j); i--; j--;
      unionConnect(ind,i,j);
    }
    rep(i,n) num[i] = 0;
    rep(i,n) num[unionGet(ind,i)]++;

    N=0;
    rep(i,n) if(num[i]) num[N++]=num[i];
    rep(i,N) if(num[i] > k) num[i] = k;

    sum = 0;
    rep(i,N) sum += num[i];

    res = 0;
    while(2*(N-1) > sum){
      res++;
      N--;
      if(k==1) sum--;
    }

    printf("%d\n",res);
  }

  return 0;
}