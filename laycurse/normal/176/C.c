#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int ab(int a){if(a<0)return -a; return a;}

int main(){
  int i,j,k,l,m,n;
  int x, y, x1, x2, y1, y2;
  int dx, dy;

  scanf("%d%d%d%d%d%d",&x,&y,&x1,&y1,&x2,&y2);

  dx = ab(x1-x2);
  dy = ab(y1-y2);

  if(dx <= 4 && dy <= 4 && dx+dy <= 6) puts("First");
  else puts("Second");

  return 0;
}