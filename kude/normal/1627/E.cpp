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
    int n, m, k;
    cin >> n >> m >> k;
    VL x(n);
    rep(i, n) cin >> x[i];
    struct E {
      int b, c, d, h;
    };
    vector<vector<E>> to(n);
    rep(_, k) {
      int a, b, c, d, h;
      cin >> a >> b >> c >> d >> h;
      a--, b--, c--, d--;
      to[a].emplace_back(E{b, c, d, -h});
    }
    vector<vector<pair<int, ll>>> dp(n);
    dp[0].emplace_back(0, 0);
    vector<pair<int, ll>> d;
    rep(i, n) {
      if (dp[i].empty()) continue;
      sort(all(dp[i]));
      d.clear();
      for(auto [j, v] : dp[i]) {
        if (d.size() && d.back().second + x[i] * (j - d.back().first) <= v) continue;
        while(d.size() && v + x[i] * (j - d.back().first) <= d.back().second) d.pop_back();
        d.emplace_back(j, v);
      }
      sort(all(to[i]), [](const E& x, const E& y) {
        return x.b < y.b;
      });
      int idx = 0;
      for(auto [b, c, dj, h] : to[i]) {
        while(idx < d.size() && d[idx].first < b) idx++;
        for(int p : {idx - 1, idx}) {
          if (!(0 <= p && p < d.size())) continue;
          ll v = d[p].second + abs(d[p].first - b) * x[i];
          dp[c].emplace_back(dj, v + h);
        }
      }
    }
    if (dp[n - 1].empty()) {
      cout << "NO ESCAPE\n";
      continue;
    }
    ll ans = 1002003004005006007;
    for(auto [j, v] : dp[n - 1]) chmin(ans, v + (m - 1 - j) * x[n - 1]);
    cout << ans << '\n';
  }
}