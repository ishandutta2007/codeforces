#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  double a[100], b[100], x, lim, res;

  scanf("%d%lf",&n,&lim);
  rep(i,n) scanf("%lf",a+i);
  rep(i,n) scanf("%lf",b+i);
  x = 1e100;
  rep(i,n) if(x > b[i]/a[i]) x = b[i]/a[i];
  res=0;
  rep(i,n) res += a[i]*x;
  if(res > lim) res = lim;
  printf("%.10lf\n",res);

  return 0;
}