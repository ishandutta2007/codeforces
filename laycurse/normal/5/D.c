#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int loop;
  double mx_speed, length, point, ac, lim, res;
  double t1,t2,a,b,c,dist,st;

  scanf("%lf%lf%lf%lf%lf",&ac,&mx_speed,&length,&point,&lim);
  if(lim > mx_speed) lim = mx_speed;

  res=0;

  a=0; b=mx_speed;
  rep(loop,100){
    c=(a+b)/2;
    t1 = c/ac;
    t2 = 0; if(c>lim) t2 = (c-lim)/ac;
    dist = t1 * c / 2 + t2 * (c+lim) / 2;

    if(dist > point) b=c; else a=c;
  }

  res += t1 + t2 + (point-dist)/mx_speed;

  st=c; if(st>lim) st=lim;
  t1 = (mx_speed-st)/ac;
  dist = t1*(mx_speed+st)/2;

  if(dist > length-point){
    a=st; b=mx_speed;
    rep(loop,100){
      c=(a+b)/2;
      t1 = (c-st)/ac;
      dist = t1*(c+st)/2;
      if(dist > length-point) b=c; else a=c;
    }
    res += t1;
  } else {
    res += t1 + (length-point-dist)/mx_speed;
  }

  printf("%.10lf\n",res);

  return 0;
}