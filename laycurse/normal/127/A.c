#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

double dist(double dx, double dy){
  return sqrt(dx*dx + dy*dy);
}

int main(){
  int i, n, k;
  double x[111], y[111], res = 0;

  scanf("%d%d",&n,&k);
  rep(i,n) scanf("%lf%lf",x+i,y+i);
  REP(i,1,n) res += dist(x[i]-x[i-1], y[i]-y[i-1]);

  res /= 50;
  res *= k;

  printf("%.10f\n",res);

  return 0;
}