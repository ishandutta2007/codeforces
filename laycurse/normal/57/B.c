#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,q,in;
  long long res;
  int a[100000], b[100000], c[100000];

  while(scanf("%d%d%d",&n,&m,&q)==3){
    res = 0;
    rep(i,m) scanf("%d%d%d",a+i,b+i,c+i);
    while(q--){
      scanf("%d",&in);
      rep(i,m) if(a[i] <= in && in <= b[i]) res += in-a[i]+c[i];
    }
    printf("%I64d\n",res);
    break;
  }

  return 0;
}