#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  char in[110000];

  scanf("%s",in);
  n = strlen(in);

  rep(i,n) if(in[i]=='0') break;
  if(i==n) i = n-1;

  rep(k,n) if(i!=k) putchar(in[k]);
  puts("");

  return 0;
}