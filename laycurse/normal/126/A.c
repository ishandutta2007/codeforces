#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
int GCD(int a,int b){int r; while(a){r=b; b=a; a=r%a;} return b;}

int main(){
  int i,j,k,l,m,n;
  int t1,t2,x1,x2,t0;
  double opt, tmp;
  int r1, r2;
  ll y1, y2, yy1, yy2;

  while(scanf("%d%d%d%d%d",&t1,&t2,&x1,&x2,&t0)==5){
    opt = 1e100;

    if(t1==t0 && t2==t0){
      printf("%d %d\n",x1,x2);
      continue;
    }
    if(t1==t0){
      printf("%d 0\n",x1);
      continue;
    }
    if(t2==t0){
      printf("0 %d\n",x2);
      continue;
    }
    
    y2 = 1;
    REP(y1,0,x1+1){
      while(t1*y1+t2*y2 < t0*(y1+y2)){
        y2++;
        if(y2 > x2) break;
      }
      if(y2 > x2) break;

      k = GCD(y1, y2);
      if(k>1) continue;

      tmp = (t1*y1+t2*y2) / (double)(y1+y2);
      if(opt > tmp){
        opt = tmp;

        k = 1000000000;
        if(y1 && k > x1 / y1) k = x1 / y1;
        if(y2 && k > x2 / y2) k = x2 / y2;

        r1 = y1 * k;
        r2 = y2 * k;
      }
    }

    printf("%d %d\n",r1,r2);
  }

  return 0;
}