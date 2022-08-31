#include<stdio.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int upup = 0, res = 0;
  char c;

  for(;;){
    c=getchar();
    if(c=='('){
      upup++;
    } else if(c==')'){
      if(upup) upup--, res++;
    } else {
      break;
    }
  }

  printf("%d\n",res*2);

  return 0;
}