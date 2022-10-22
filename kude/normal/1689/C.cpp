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
    constexpr int INF = 1001001001;
    auto dfs = [&](auto self, int u, int p, int d) -> int {
      int cnt = 0;
      for(int v: to[u]) if (v != p) {
        cnt++;
      }
      if (cnt == 0) return 2 * d + 1;
      else if (cnt == 1) return 2 * d + 2;
      int res = INF;
      for(int v: to[u]) if (v != p) {
        chmin(res, self(self, v, u, d + 1));
      }
      return res;
    };
    int ans = dfs(dfs, 0, -1, 0);
    cout << n - ans << '\n';
  }
}