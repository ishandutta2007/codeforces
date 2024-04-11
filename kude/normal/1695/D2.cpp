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
    int n;
    cin >> n;
    VVI to(n);
    rep(_, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v);
      to[v].emplace_back(u);
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    int r = -1;
    rep(i, n) if ((int)to[i].size() >= 3) {
      r = i;
      break;
    }
    if (r == -1) {
      cout << 1 << '\n';
      continue;
    }
    int ans = 0;
    auto dfs = [&](auto self, int u, int p) -> bool {
      bool res = false;
      int unused = 0;
      for(int v: to[u]) if (v != p) {
        bool r = self(self, v, u);
        if (r) res = true;
        else unused++;
      }
      if (unused >= 2) {
        res = true;
        ans += unused - 1;
      }
      return res;
    };
    dfs(dfs, r, -1);
    cout << ans << '\n';
  }
}