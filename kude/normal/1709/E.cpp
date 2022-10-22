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
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    VVI to(n);
    rep(i, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v);
      to[v].emplace_back(u);
    }
    int ans = 0;
    auto dfs = [&](auto self, int u, int p, int acc) -> set<int> {
      acc ^= a[u];
      set<int> st;
      st.emplace(acc);
      bool bad = false;
      for(int v: to[u]) if (v != p) {
        auto r = self(self, v, u, acc);
        if (bad) continue;
        if (st.size() < r.size()) swap(st, r);
        for(int x: r) {
          if (st.count(x ^ a[u])) {
            bad = true;
            ans++;
            st.clear();
            break;
          }
        }
        if (!bad) st.insert(all(r));
      }
      return st;
    };
    dfs(dfs, 0, -1, 0);
    cout << ans << '\n';
  }
}