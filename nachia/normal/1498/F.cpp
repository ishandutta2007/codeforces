
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,K;
vector<vector<int>> E;
vector<int> A;
vector<int> P;
vector<int> I;

int dp[100000][40];
int dp2[100000][40];

void bfs(){
  queue<int> Q;
  P.assign(N,-1);
  Q.push(0);
  while(Q.size()){
    int p=Q.front(); Q.pop();
    I.push_back(p);
    for(int e:E[p]) if(P[p]!=e){
      P[e]=p; Q.push(e);
    }
  }
}

int main(){
  scanf("%d%d",&N,&K);
  E.resize(N);
  rep(i,N-1){
    int u,v; scanf("%d%d",&u,&v); u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  A.resize(N);
  rep(i,N) scanf("%d",&A[i]);

  bfs();
  rep(i,N){ rep(k,K*2) dp[i][k]=0; dp[i][0]=A[i]; }
  for(int i=N-1; i>=1; i--){
    int p=I[i];
    rep(k,K*2-1) dp[P[p]][k+1]^=dp[p][k];
    dp[P[p]][0]^=dp[p][K*2-1];
  }
  
  rep(i,N) rep(k,K*2) dp2[i][k]=0;
  for(int e:E[0]) rep(k,K*2) dp2[e][(k+1)%(K*2)] ^= dp[e][(k+K*2-1)%(K*2)]^dp[0][k];
  for(int i=1; i<N; i++){
    int p=I[i];
    for(int e:E[p]) if(P[p]!=e){
      rep(k,K*2-1) dp2[e][k+1]^=dp2[p][k];
      rep(k,K*2) dp2[e][(k+1)%(K*2)] ^= dp[e][(k+K*2-1)%(K*2)]^dp[p][k];
      dp2[e][0]^=dp2[p][K*2-1];
    }
  }
/*
  rep(i,N){
    cout<<"DP 1 : "; rep(k,K*2) cout<<dp[i][k]<<" ";
    cout<<endl;
  }
  rep(i,N){
    cout<<"DP 2 : "; rep(k,K*2) cout<<dp2[i][k]<<" ";
    cout<<endl;
  }
*/
  rep(i,N){
    if(i) printf(" ");
    int res=0;
    rep(k,K) res^=dp[i][K+k];
    rep(k,K) res^=dp2[i][K+k];
    if(res==0) printf("0"); else printf("1");
  }
  printf("\n");

  return 0;
}