#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int n, m, sz[51];
double dp[51][51][51];
double con[51][51];

void solve(int rest,int st){
  int i,j,k,mm;
  double p, per;

  if(dp[rest][st][0] > -0.5) return;

  rep(k,n+1) dp[rest][st][k] = 0;

  if(st==m-1){
    dp[rest][st][(rest+sz[st]-1)/sz[st]] = 1;
    return;
  }

  p = 1 / (double)(m-st);
  rep(k,rest+1){
    solve(rest-k, st+1);
    per = con[rest][k] * pow(p,k) * pow(1-p,rest-k);
    mm = (k+sz[st]-1)/sz[st];
    rep(i,n+1){
      j = mm; if(j<i) j = i;
      dp[rest][st][j] += dp[rest-k][st+1][i] * per;
    }
  }
}

int main(){
  int i,j,k,l;
  double res;

  con[0][0]=1; REP(j,1,51) con[0][j]=0;
  REP(i,1,51){ con[i][0]=1; REP(j,1,51) con[i][j]=con[i-1][j-1]+con[i-1][j]; }

  rep(i,51) rep(j,51) rep(k,51) dp[i][j][k]=-1;
  scanf("%d%d",&n,&m);
  rep(i,m) scanf("%d",sz+i);

  solve(n,0);

  res=0;
  rep(i,n+1) res += dp[n][0][i] * i;
  printf("%.10lf\n",res);

  return 0;
}