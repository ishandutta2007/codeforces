#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x[555555], v[555555];
double mx[555555];

int main(){
  int i,j,k,l,m,n,loop;
  int st,ed;
  double a=0, b=1e10, c;
  double tmp, nn;

  scanf("%d",&n);
  rep(i,n) scanf("%d%d",x+i,v+i);

  rep(i,n) if(v[i]>0) break; st=i;
  for(i=n-1;i>=0;i--) if(v[i]<0) break; ed=i;

  if(st > ed){ puts("-1"); return 0; }

  rep(loop,80){
    c = (a+b)/2;

    tmp = -1e100;
    rep(i,n){
      if(v[i]<0){ mx[i]=tmp; continue; }
      nn = x[i] + v[i] * c;
      if(tmp < nn) tmp = nn;
      mx[i] = nn;
    }

    tmp = 1e100;
    for(i=n-1;i>=0;i--){
      if(v[i]>0) continue;
      nn = x[i] + v[i] * c;
      if(tmp > nn) tmp = nn;
      if(tmp < mx[i]) break;
    }

    if(i>=0) b=c; else a=c;
  }

  printf("%.12lf\n",(a+b)/2);

  return 0;
}