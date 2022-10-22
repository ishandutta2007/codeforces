
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void chmax(int& l,int r){ if(l<r) l=r; }

int N,M;
vector<int> dp,dp2;

int main(){
  scanf("%d%d",&N,&M);
  dp.assign(M+1,-1);
  dp[0]=0;
  rep(q,N){
    int t; scanf("%d",&t);
    dp2.assign(M+1,-1);
    if(t==1){
      ll x; int y; scanf("%lld%d",&x,&y);
      rep(i,M+1) if(dp[i]!=-1) dp2[i]=y;
      rep(i,M+1) if(dp2[i]!=-1){
        if(i+(x+99999)/100000<=M) chmax(dp2[i+(x+99999)/100000],dp2[i]-1);
        if(dp[i]==-1) dp[i]=q+1;
      }
    }
    if(t==2){
      ll x; int y; scanf("%lld%d",&x,&y);
      rep(i,M+1) if(dp[i]!=-1) dp2[i]=y;
      rep(i,M+1) if(dp2[i]!=-1){
        if((i*x+99999)/100000<=M) chmax(dp2[(i*x+99999)/100000],dp2[i]-1);
        if(dp[i]==-1) dp[i]=q+1;
      }
    }
  }
  for(int i=1; i<=M; i++){ if(i!=1) printf(" "); printf("%d",dp[i]); } printf("\n");
  return 0;
}