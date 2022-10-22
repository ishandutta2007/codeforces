#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

bool intersect_chord(pair<int,int> a, pair<int,int> b){
  rep(t,2){
    swap(a,b);
    if(a.first < b.first && b.first < a.second && a.second < b.second) return true;
  }
  return false;
}

int testcase(){
  int N,K; cin >> N >> K;
  vector<int> used(2*N,0);
  vector<pair<int,int>> G;
  rep(i,K){
    int u,v; cin >> u >> v; u--; v--;
    if(u > v) swap(u,v);
    used[u] = used[v] = 1;
    G.push_back({u,v});
  }
  int preans = 0;
  rep(i,K) rep(j,i){
    if(intersect_chord(G[i],G[j])) preans++;
  }
  if(N == K) return preans;
  vector<int> unusedList;
  rep(i,2*N) if(used[i] == 0) unusedList.push_back(i);
  vector<pair<int,int>> cand;
  rep(i,unusedList.size()/2){
    cand.push_back({ unusedList[i], unusedList[i+(N-K)] });
  }
  int dans = 0;
  dans += (N-K) * (N-K-1) / 2;
  for(auto a : G) for(auto b : cand){
    if(intersect_chord(a,b)) dans++;
  }
  return preans + dans;
}

int main(){
  int T; cin >> T;
  while(T--) cout << testcase() << "\n";
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;