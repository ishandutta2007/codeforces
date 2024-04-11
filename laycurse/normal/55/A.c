#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int reach[1010][1010];

int main(){
  int i,j,k,l,m,n,now,s;

  while(scanf("%d",&n)==1){
    rep(i,n) rep(j,n) reach[i][j] = 0;
    now=0; s=1;

    while(!reach[now][s]){
      reach[now][s]=1;
      now = (now+s)%n;
      s = (s+1)%n;
    }

    rep(i,n){
      rep(j,n) if(reach[i][j]) break;
      if(j==n) break;
    }

    if(i<n) puts("NO"); else puts("YES");
  }

  return 0;
}