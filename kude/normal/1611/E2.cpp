#include<bits/stdc++.h>
namespace {
using namespace std;
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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    VI x(k);
    rep(i, k) cin >> x[i], x[i]--;
    vector<char> floc(n);
    for(int t: x) floc[t] = true;
    VVI to(n);
    rep(_, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].push_back(v);
      to[v].push_back(u);
    }
    bool ok = true;
    int ans = 0;
    VI st;
    vector<char> loc(n);
    auto dfs1 = [&](auto&& self, int u, int p=-1) -> void {
      st.push_back(u);
      if (floc[u]) {
        loc[st[st.size() / 2]] = true;
      }
      for(int v: to[u]) if (v != p) {
        self(self, v, u);
      }
      st.pop_back();
    };
    dfs1(dfs1, 0);
    auto dfs2 = [&](auto&& self, int u, int p=-1) -> void {
      if (loc[u]) {
        ans++;
        return;
      }
      if (p != -1 && to[u].size() == 1) {
        ok = false;
        return;
      }
      for(int v: to[u]) if (v != p) {
        self(self, v, u);
      }
    };
    dfs2(dfs2, 0);
    if (!ok) cout << -1 << '\n';
    else cout << ans << '\n';
  }
}