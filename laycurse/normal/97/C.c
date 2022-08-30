#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  double in[120];
  double res,tmp;
  double x,y;

  while(scanf("%d",&n)==1){
    rep(i,n+1) scanf("%lf",in+i);
    res = 0;
    if(n%2==0) res = in[n/2];

    rep(i,(n+1)/2) REP(j,(n+2)/2,n+1){
      y = (n/2.0 - i) / (double) (j-i);
      x = 1-y;

      tmp = x * in[i] + y * in[j];
      if(res < tmp) res = tmp;
    }

    printf("%.10lf\n",res);
  }

  return 0;
}