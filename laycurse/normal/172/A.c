#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char in[40000][25];

int main(){
  int i,j,k,l,m,n;

  scanf("%d",&n);
  rep(i,n) scanf("%s",in[i]);

  for(k=0;;k++){
    rep(i,n) if(in[i][k] != in[0][k]) break;
    if(i < n) break;
  }

  printf("%d\n",k);

  return 0;
}