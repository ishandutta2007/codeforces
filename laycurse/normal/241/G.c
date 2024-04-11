#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,x;
  n = 500;
  x = 0;

  printf("%d\n",n);
  rep(i,n){
    k = 600-i;
    if(i==0 || i==n-1) k = 1000000;
    if(!(i==0 || i==n-1)) x += 2*k;
    if(i==n-1) x += 10000;
    printf("%d %d\n",x,k);
  }

  return 0;
}