#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int in[200];

  scanf("%d",&n);
  rep(i,n){
    scanf("%d",&k);
    k--;
    in[k] = i;
  }
  rep(i,n){
    if(i) putchar(' ');
    printf("%d",in[i]+1);
  }
  puts("");

  return 0;
}