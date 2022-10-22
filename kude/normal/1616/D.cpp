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
    int n;
    cin >> n;
    VI a(n + 2);
    rep(i, n) cin >> a[i + 1];
    int x;
    cin >> x;
    rep(i, n) a[i + 1] -= x;
    constexpr int INF = 1001001001;
    a[0] = a[n + 1] = -INF;
    array<int, 4> dp{0, -INF, 1, -INF};
    for(int i = 1; i <= n; i++) {
      bool ok[8];
      rep(s, 8) ok[s] = true;
      if (a[i - 1] + a[i] < 0) ok[3] = ok[7] = false;
      if (a[i] + a[i + 1] < 0) ok[6] = ok[7] = false;
      if (a[i - 1] + a[i] + a[i + 1] < 0) ok[7] = false;
      if (i == n) rep(s, 4) ok[s | 4] = false;
      array<int, 4> ndp{-INF, -INF, -INF, -INF};
      rep(s, 4) {
        rep(b, 2) {
          int ns = s | (b << 2);
          if (ok[ns]) chmax(ndp[ns >> 1], dp[s] + b);
        }
      }
      dp = ndp;
    }
    int ans = *max_element(all(dp));
    cout << ans << '\n';
  }
}