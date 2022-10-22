#include<bits/stdc++.h>
namespace {
using namespace std;
// #include<atcoder/maxflow>
// using namespace atcoder;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    VVI to(n);
    rep(_, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v);
      to[v].emplace_back(u);
    }
    // VVI par(n, -1);
    VI d;
    auto dfs = [&](auto&& self, int u, int p) -> int {
      int res = 0;
      for(int v: to[u]) if (v != p) {
        // par[v] = u;
        int r = self(self, v, u);
        // cout << u << ' ' << v << ' ' << r << endl;
        if (r + 1 > res) {
          if (res) d.emplace_back(res - 1);
          res = r + 1;
        } else {
          d.emplace_back(r);
        }
      }
      return res;
    };
    d.emplace_back(dfs(dfs, 0, -1));
    int sz = d.size();
    int r = -1, w = -1, g = -1;
    // rep(i, sz) cout << d[i] << ' ';
    // cout << endl;
    // exit(0);
    if (sz <= k) {
      w = n - sz;
      r = sz;
      k -= sz;
      ll ans = 0;
      rep(i, min(k, w) + 1) chmax(ans, ll(r + i) * (w - i));
      cout << ans << '\n';
      continue;
    }
    sort(rall(d));
    w = 0;
    rep(i, k) w += d[i];
    r = k;
    g = n - r - w;
    ll ans = 1002003004005006007LL;
    rep(i, g + 1) chmin(ans, ll(w + i) * (r - (g - i)));
    cout << ans << '\n';
  }
}