#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define M 1000003

int main(){
  int i,j,k,l,m,n;
  int res[10000];

  res[0]=res[1]=1;
  REP(i,2,10000) res[i] = (res[i-1]*3)%M;

  while(scanf("%d",&n)==1) printf("%d\n",res[n]);

  return 0;
}