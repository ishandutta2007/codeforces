#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int get_d(int x,int y,int n){
  if(x==0) return y;
  if(y==n) return x+n;
  if(x==n) return (n-y)+n+n;
  return (n-x)+n+n+n;
}

int main(){
  int i,j,k,l,m,n;
  int x1,x2,y1,y2,d1,d2,res;

  while(scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2)==5){
    d1 = get_d(x1,y1,n);
    d2 = get_d(x2,y2,n);
    res = d1-d2;
    if(res<0) res = -res;
    if(res > 4*n-res) res = 4*n-res;
    printf("%d\n",res);
    break;
  }

  return 0;
}