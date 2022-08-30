#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,rest;

  while(scanf("%d",&n)==1){
    k=1; m=2; printf("2"); rest=n-2;
    while(rest--){
      k=(k+m)%n; m++;
      printf(" %d",k+1);
    }
    puts("");
    break;
  }

  return 0;
}