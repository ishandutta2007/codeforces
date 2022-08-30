#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int size;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&n);
    n-=2;
    if(n<0) n=0;
    printf("%d\n",n);
  }

  return 0;
}