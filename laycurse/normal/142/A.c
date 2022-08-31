#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  int in;
  ll i,j,k,l,m,n;
  ll res1, res2;

  while(scanf("%d",&in)==1){
    n = in;
    res1 = res2 = 2*3*(n+2);

    for(i=1;i*i*i<=n;i++) if(n%i==0){
      m = n/i;
      for(j=i;j*j<=m;j++) if(m%j==0){
        k = m/j;

        l = (i+1)*(j+2)*(k+2);
        if(res1 > l) res1 = l; if(res2 < l) res2 = l;
        l = (i+2)*(j+1)*(k+2);
        if(res1 > l) res1 = l; if(res2 < l) res2 = l;
        l = (i+2)*(j+2)*(k+1);
        if(res1 > l) res1 = l; if(res2 < l) res2 = l;
      }
    }

    res1 -= n;
    res2 -= n;
    printf("%I64d %I64d\n",res1,res2);
  }

  return 0;
}