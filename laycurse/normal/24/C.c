#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int solve(int st, int x[], int n, int step){
  int i;
  rep(i,step) st += 2*(x[i%n]-st);
  return st;
}

int x[100001], y[100001];
int main(){
  int i,j,k,l,m,n;
  int sx,sy,ex,ey;
  ll step;

  scanf("%d%I64lld",&n,&step);
  scanf("%d%d",&sx,&sy);
  rep(i,n) scanf("%d%d",x+i,y+i);

  ex = solve(sx,x,n,step%(2*n));
  ey = solve(sy,y,n,step%(2*n));

  printf("%d %d\n",ex,ey);

  return 0;
}