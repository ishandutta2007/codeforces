#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

template<class E>
E& chmin(E& l,E r){ return l=min(l,r); }

const int INF=1000000000;

int N;
string S;
int dp[100005][8];

void loop(){
  cin>>S;
  S.push_back('$'); S.push_back('#');
  reverse(S.begin(),S.end());
  N=S.size();
  rep(i,N+1) rep(j,8) dp[i][j]=INF;
  dp[2][0]=0;
  for(int i=2; i<N; i++){
    rep(p,8) rep(q,2) chmin(dp[i+1][p%4*2+q],dp[i][p]+q);
    if(S[i-1]==S[i]) rep(p,8) if(!(p&3)) dp[i+1][p]=INF;
    if(S[i-2]==S[i]) rep(p,8) if(!(p&5)) dp[i+1][p]=INF;
  }
  int ans=INF; rep(i,8) chmin(ans,dp[N][i]);
  cout<<ans<<endl;
}

int main(){
	int T; cin>>T;
  while(T--) loop();
	return 0;
}