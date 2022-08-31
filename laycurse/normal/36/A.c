#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  char in[1000];
  int num[1000], sz, len;

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  scanf("%d%s",&len,in);
  sz=0;
  rep(i,len){
    if(in[i]<' ') break;
    if(in[i]=='1') num[sz++]=i;
  }

  REP(i,2,sz) if(num[i]-num[i-1] != num[i-1]-num[i-2]) break;
  if(i==sz) puts("YES"); else puts("NO");

  return 0;
}