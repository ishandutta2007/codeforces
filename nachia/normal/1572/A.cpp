#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)


vector<vector<int>> SCC(const vector<vector<int>>& E) {
    int n = E.size();
    vector<int> F(n, 0), St, I, perm, g;
    vector<vector<int>> R(n), G, res;
    rep(i, n) if (F[i] == 0) {
        St.push_back(i);
        while (St.size()) {
            int p = St.back();
            St.pop_back();
            if (p < 0) { I.push_back(-1 - p); continue; }
            if (F[p]) continue;
            F[p] = -1;
            St.push_back(-1 - p);
            for (int e : E[p]) St.push_back(e);
        }
    }
    rep(i, n) for (int e : E[i]) R[e].push_back(i);
    reverse(I.begin(), I.end());
    for (int s : I) if (F[s] == -1) {
        g = { s };
        F[s] = G.size();
        rep(i, g.size()) {
            int p = g[i];
            for (int e : R[p]) if (F[e] == -1) {
                F[e] = G.size();
                g.push_back(e);
            }
        }
        G.emplace_back(move(g));
    }
    I.assign(G.size(), 0);
    rep(i, n) for (int e : E[i]) if (F[i] != F[e]) I[F[e]]++;
    rep(i, G.size()) if (I[i] == 0) perm.push_back(i);
    rep(i, perm.size()) for (int p : G[i]) {
        for (int e : E[p]) if (--I[F[e]] == 0) perm.push_back(F[e]);
    }
    for (auto p : perm) res.emplace_back(move(G[p]));
    return res;
}


void testcase(){
  int N; cin >> N;
  vector<vector<int>> E(N);
  rep(i,N){
    int k; cin >> k;
    rep(j,k){
      int a; cin >> a; a--;
      E[a].push_back(i);
    }
  }
  auto I = SCC(E);
  if(I.size() != N){ cout << "-1\n"; return; }
  vector<int> D(N,1);
  for(auto& Iarr : I){
    int p = Iarr[0];
    for(int e : E[p]){
      if(e > p) D[e] = max(D[e], D[p]);
      else D[e] = max(D[e], D[p] + 1);
    }
  }
  int ans = 0;
  for(int d : D) ans = max(ans, d);
  cout << ans << endl;
}


int main(){
  int T; cin >> T;
  rep(t,T) testcase();
  return 0;
}




struct ios_do_not_sync {
    ios_do_not_sync() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} ios_do_not_sync_instance;