#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007

ll pw(ll a,ll b){
  ll r;
  if(b==0) return 1;
  r = pw(a,b/2);
  r = (r*r)%M;
  if(b%2) r=(r*a)%M;
  return r;
}

int X[120], Y[120], n;
ll fact[12000], facti[12000];
ll dp[120][12000];
ll comb[12000][120];
ll people[120], cap[120];

ll solve(int st,int rest){
  int i,j,k,mx;
  ll res=0;

  if(rest<0) return 0;
  if(dp[st][rest]>=0) return dp[st][rest];
  if(st==n){
    if(rest==0) res++;
    return dp[st][rest] = res;
  }

  if(rest + (people[n]-people[st]) - (cap[n]-cap[st]) > 0){ return dp[st][rest]=0; }

  mx = Y[st]; if(rest+X[st]<mx) mx = rest+X[st];
  rep(i,mx+1){
    res += solve(st+1,rest+X[st]-i) * comb[rest+X[st]][i];
    res %= M;
  }

  return dp[st][rest]=res;
}

int main(){
  int i,j,k,l,m;
  ll res, sum;

  fact[0]=1; REP(i,1,12000) fact[i]=(fact[i-1]*i)%M;
  rep(i,12000) facti[i]=pw(fact[i],M-2);

  comb[0][0]=1; REP(j,1,120) comb[0][j]=0;
  REP(i,1,12000){
    comb[i][0]=1; REP(j,1,120) comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%M;
  }

  scanf("%d",&n);
  rep(i,n) scanf("%d",X+i);
  rep(i,n) scanf("%d",Y+i);
  sum = 0; rep(i,n) sum += X[i];
  people[0]=0; rep(i,n) people[i+1]=people[i]+X[i];
  cap[0]=0; rep(i,n) cap[i+1]=cap[i]+Y[i];

  rep(i,n+1) rep(j,sum+1) dp[i][j] = -1;
  res = solve(0,0);

  res = (res * fact[sum])%M;
  rep(i,n) res = (res * facti[X[i]])%M;

  printf("%d\n",(int)res);

  return 0;
}