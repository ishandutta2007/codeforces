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
    int n, k;
    cin >> n >> k;
    VVI to(n);
    for(int i = 1; i < n; i++) {
      int p;
      cin >> p;
      to[p-1].emplace_back(i);
    }
    VL s(n);
    rep(i, n) cin >> s[i];
    auto dfs = [&](auto self, int u, int k) -> pair<ll, ll> {
      ll r0 = s[u] * k;
      ll r1 = s[u] * (k + 1);
      if (to[u].size() == 0) return {r0, r1};
      if (to[u].size() == 1) {
        int v = to[u][0];
        auto [t0, t1] = self(self, v, k);
        return {t0 + r0, t1 + r1};
      }
      int c = to[u].size();
      VL res(c);
      ll b0 = 0;
      rep(i, c) {
        auto [t0, t1] = self(self, to[u][i], k / c);
        b0 += t0;
        res[i] = t1 - t0;
      }
      sort(rall(res));
      r0 += b0;
      r1 += b0;
      r0 += accumulate(res.begin(), res.begin() + k % c, 0LL);
      r1 += accumulate(res.begin(), res.begin() + k % c + 1, 0LL);
      return {r0, r1};
    };
    auto [r0, r1] = dfs(dfs, 0, k);
    cout << r0 << '\n';
  }
}