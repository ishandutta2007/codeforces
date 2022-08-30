#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int res, tmp, cnt;
  char in[1200];

  while(scanf("%d%s",&n,in)==2){
    res=1000000000;
    cnt=0; rep(i,n) if(in[i]=='T') cnt++;
    rep(k,n){
      tmp = 0;
      rep(i,cnt) if(in[(k+i)%n]=='H') tmp++;
      if(res > tmp) res = tmp;
    }
    printf("%d\n",res);
  }

  return 0;
}