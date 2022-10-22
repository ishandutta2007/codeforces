#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


int main(){
  int N, K; cin >> N >> K;
  vector<int> A(N*K); rep(i,N*K){ cin >> A[i]; A[i]--; }
  vector<vector<int>> to(N,vector<int>(N*K+2,N*K+1));
  vector<vector<int>> to2(N,vector<int>(N*K+2,N*K+1));
  for(int p=N*K-1; p>=0; p--){
    rep(n,N) to[n][p] = to[n][p+1];
    to[A[p]][p] = p+1;
  }
  for(int p=N*K+1; p>=0; p--) rep(n,N) to2[n][p] = to[n][to[n][p]];
  vector<pair<int,int>> ans(N);
  vector<int> used(N,0);
  vector<int> I;
  int t = (N-1) / (K-1) + 1;
  rep(i,N){
    int l = 0; if(i >= t) l = ans[I[i-t]].second + 1;
    int col = 0;
    while(used[col]) col++;
    rep(j,N) if(!used[j]) if(to2[col][l] > to2[j][l]) col = j;
    used[col] = 1;
    I.push_back(col);
    ans[col] = { to[col][l]-1, to2[col][l]-1 };
  }
  for(auto a : ans) cout << (a.first+1) << " " << (a.second+1) << "\n";
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;