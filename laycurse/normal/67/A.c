#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int res[1200];
  char in[1200];

  while(scanf("%d%s",&n,in)==2){
    rep(i,n) res[i] = 1;
    for(;;){
      int fg = 0;
      rep(i,n-1){
        if(in[i]=='L'){
          if(res[i] < res[i+1]+1) res[i] = res[i+1]+1, fg++;
        }
        if(in[i]=='R'){
          if(res[i+1] < res[i]+1) res[i+1] = res[i]+1, fg++;
        }
        if(in[i]=='='){
          if(res[i] > res[i+1]) res[i+1] = res[i], fg++;
          if(res[i] < res[i+1]) res[i] = res[i+1], fg++;
        }
      }
      if(!fg) break;
    }
    rep(i,n){
      if(i) putchar(' ');
      printf("%d",res[i]);
    }
    puts("");
  }

  return 0;
}