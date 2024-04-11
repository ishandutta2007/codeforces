#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

ll dp[20][600000], res;
int edge[20][20];
int bc[600000], bt[600000];

int main(){
  int i,j,k,kk,l,m,n,st,rest,all;

  bc[0]=0; REP(i,1,1<<19) bc[i]=bc[i&(i-1)]+1;
  rep(i,19) bt[1<<i]=i;

  res=0;
  scanf("%d%d",&n,&m);
  rep(i,n) rep(j,n) edge[i][j]=0;
  while(m--){
    scanf("%d%d",&i,&j); i--; j--;
    edge[i][j]=edge[j][i]=1;
  }

  res=0;
  all = (1<<n)-1;

  rep(st,n){
    rep(i,n) rep(j,1<<n) dp[i][j]=0;
    dp[st][0]=1;
    rep(j,1<<n) if(!(j&1<<st)) rep(i,n) if(dp[i][j]){
      rest = (all^j);
      while(rest){
        kk=(rest&-rest); k=bt[kk]; rest^=kk;
        if(edge[i][k]) dp[k][j|kk]+=dp[i][j];
      }
    }
    rep(j,1<<n) if(bc[j]>=3) res += dp[st][j];

    rep(i,n) edge[st][i]=edge[i][st]=0;
  }

  res /= 2;
  printf("%I64lld\n",res);

  return 0;
}