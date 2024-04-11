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
  int n;
  cin >> n;
  vector<vector<P>> to(n);
  rep(_, n - 1) {
    int u, v, x;
    cin >> u >> v >> x;
    u--, v--, x--;
    to[u].emplace_back(v, x);
    to[v].emplace_back(u, x);
  }
  VI sz(2 * n, 1);
  VI d1(2 * n), d2(2 * n);
  VI pre(n);
  ll ans = 0;
  auto dfs = [&](auto self, int u, int p) -> void {
    for(auto [v, x]: to[u]) if (v != p) {
      int w = pre[x];
      pre[x] = v;
      self(self, v, u);
      pre[x] = w;
      sz[u] += sz[v];
      d1[w] += sz[v];
      int csz = sz[v] - d1[v];
      d2[w] += csz;
      ans += ll(csz) * d2[v];
    }
  };
  rep(i, n) pre[i] = n + i;
  dfs(dfs, 0, -1);
  rep(i, n) ans += ll(n - d1[n + i]) * d2[n + i];
  cout << ans << '\n';
}