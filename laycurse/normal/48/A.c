#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  char in[3][100];
  char g[333], *res[4]={"F","M","S","?"};

  g['r'] = 's';
  g['s'] = 'p';
  g['p'] = 'r';

  while(scanf("%s%s%s",in[0],in[1],in[2])==3){
    rep(i,3){
      rep(j,3) if(i!=j) if(in[j][0] != g[in[i][0]]) break;
      if(j==3) break;
    }
    puts(res[i]);
  }

  return 0;
}