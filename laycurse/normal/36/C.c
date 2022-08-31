#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10

double solve(double h1,double r1,double R1,double h2,double r2,double R2){
  double tmp, res=0;

  if(r1 > r2-EPS){
    tmp = h2*(r1-r2)/(R2-r2);
    if(tmp > res) res = tmp;
  }
  if(R1 < R2-EPS){
    tmp = h2*(R1-r2)/(R2-r2) - h1;
    if(tmp > res) res = tmp;
  }
  if(R1 > R2-EPS){
    tmp = h2 - h1*(R2-r1)/(R1-r1);
    if(tmp > res) res = tmp;
  }

  if(res > h2) res = h2;

  return res;
}

int main(){
  int i,j,k,l,m,n;
  double h[3333], r[3333], R[3333], p[3333], res, mx;

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  scanf("%d",&n);
  rep(i,n) scanf("%lf%lf%lf",h+i,r+i,R+i);
  rep(i,n) p[i]=0;
  rep(i,n) rep(j,i){
    mx = solve(h[i],r[i],R[i],h[j],r[j],R[j]) + p[j];
    if(mx > p[i]) p[i] = mx;
  }

  res=0;
  rep(i,n) if(res < p[i]+h[i]) res = p[i]+h[i];
  printf("%.10lf\n",res);

  return 0;
}