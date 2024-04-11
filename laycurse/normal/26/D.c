#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  double res;

  scanf("%d%d%d",&n,&m,&k);

  res = 1;
  rep(i,k+1){
    res *= m-i;
    res /= n+i+1;
  }
  if(res<0) res=0;
  if(res>1) res=1;

  res = 1-res;
  printf("%.10lf\n",res);

  return 0;
}