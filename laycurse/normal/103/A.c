#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  int i,j,k,l,m,n;
  ll in[120], res;

  while(scanf("%d",&n)==1){
    rep(i,n){
      scanf("%d",&k);
      in[i] = k;
    }

    res = 0;
    rep(i,n){
      res += in[i];
      res += i * (in[i]-1);
    }

    printf("%I64d\n",res);
  }


  return 0;
}