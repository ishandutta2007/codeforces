#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;

void solve(){
  int N; cin>>N;
  vector<ll> ans(N+1);
  vector<ll> U(N);
  vector<vector<ll>> S(N);
  for(int i=0; i<N; i++){ cin>>U[i]; U[i]--; }
  for(int i=0; i<N; i++){ int s; cin>>s; S[U[i]].push_back(s); }
  for(int u=0; u<N; u++){
    int Nu = S[u].size();
    vector<ll> SS(Nu+1);
    sort(S[u].begin(),S[u].end(),greater<ll>());
    for(int i=0; i<Nu; i++) SS[i+1] = SS[i] + S[u][i];
    for(int k=1; k<=Nu; k++) ans[k] += SS[Nu/k*k];
  }
  for(int k=1; k<=N; k++){
    if(k!=1) cout<<" ";
    cout<<ans[k];
  }
  cout<<"\n";
}

int main(){
  int T; cin>>T;
  while(T--){
    solve();
  }
  return 0;
}