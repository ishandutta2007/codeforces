#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int GCD(int a,int b){int r; while(a){r=b; b=a; a=r%a;} return b;}

int main(){
  int i,j,k,l,m,n;

  while(scanf("%d%d",&i,&j)==2){
    k = GCD(i-1,j-1) + 1;
    printf("%d\n",k);
  }

  return 0;
}