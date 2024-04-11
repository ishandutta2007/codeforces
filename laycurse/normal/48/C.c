#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10

int main(){
  int i,j,k,l,m,n;
  double mn, mx;
  double in[1200];

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%lf",in+i);
    mn = in[0]; mx = in[0]+1;
    REP(i,1,n){
      if(mn < in[i]/(double)(i+1)) mn = in[i]/(double)(i+1);
      if(mx > (in[i]+1)/(double)(i+1)) mx = (in[i]+1)/(double)(i+1);
    }
    k = (int)((n+1) * mn+EPS);
    l = (int)((n+1) * mx-EPS);
    if(k==l){ printf("unique\n%d\n",k); }
    else puts("not unique");
  }

  return 0;
}