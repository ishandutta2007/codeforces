#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int n, k;
double in[12000];

int solve(double c){
  int i; double sum = 0;

  rep(i,n){
    if(in[i] < c) sum -= (c-in[i]);
    else          sum += (in[i]-c) * (100-k) / 100;
  }

  if(sum > 0) return 1;
  return 0;
}

int main(){
  int i,j,l,m,loop;
  double a,b,c;

  while(scanf("%d%d",&n,&k)==2){
    rep(i,n) scanf("%lf",in+i);
    a = 0; b = 1000;

    rep(loop,70){
      c = (a+b)/2;
      if(solve(c)) a=c; else b=c;
    }

    printf("%.10lf\n",a);
  }

  return 0;
}