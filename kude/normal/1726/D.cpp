#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> g(n);
    rep(i, m) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, i);
    }
    VI ans(m);
    vector<char> visited(n);
    using T = tuple<int, int, int>;
    vector<T> es;
    vector<P> par(n, {-1, -1});
    VI depth(n);
    auto dfs = [&](auto self, int u, int p, int d) -> void {
      visited[u] = true;
      depth[u] = d;
      for(auto [v, i]: g[u]) if (v != p) {
        if (visited[v]) {
          if (depth[u] > depth[v]) {
            ans[i] = 1;
            es.emplace_back(u, v, i);
          }
        } else {
          par[v] = {u, i};
          self(self, v, u, d + 1);
        }
      }
    };
    dfs(dfs, 0, -1, 0);
    // cout << es.size() << endl;
    if (es.size() == 3) {
      // cout << tt << endl;
      // exit(0);
      sort(all(es), [&](const T& x, const T& y) {
        auto [xu, xv, xi] = x;
        auto [yu, yv, yi] = y;
        return depth[xu] < depth[yu] ||
               (depth[xu] == depth[yu] && depth[xv] > depth[yv]);
      });
      auto [u0, v0, i0] = es[0];
      auto [u1, v1, i1] = es[1];
      auto [u2, v2, i2] = es[2];
      if (u1 == u2 && v1 == u0 && v2 == v0) {
        ans[i0] = ans[i1] = 0;
        int u = par[u1].first;
        while(par[u].first != v0) {
          auto [v, i] = par[u];
          ans[i] = 1;
          u = v;
        }
      }
    }
    rep(i, m) cout << ans[i];
    cout << '\n';
  }
}