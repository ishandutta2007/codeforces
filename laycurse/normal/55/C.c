#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int x,y,win;

  while( scanf("%d%d%d",&x,&y,&n)==3 ){
    win = 0;
    while(n--){
      scanf("%d%d",&i,&j);
      i--; j--;
      if(x-i-1 < i) i = x-i-1;
      if(y-j-1 < j) j = y-j-1;
      if(i<=4 || j<=4) win = 1;
    }
    if(win) puts("YES"); else puts("NO");
    break;
  }

  return 0;
}