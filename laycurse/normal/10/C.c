#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  long long d[10];
  long long res=0;

  scanf("%d",&n);
  rep(i,10) d[i]=0;

  REP(i,1,n+1) d[i%9]++;
  rep(i,10) rep(j,10) res += d[i]*d[j]*d[(i*j)%9];
  REP(i,1,n+1) res -= n/i;
  printf("%I64d\n",res);

  return 0;
}