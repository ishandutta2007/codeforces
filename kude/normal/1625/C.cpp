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

constexpr int MX = 510;
int dp[MX][MX], ndp[MX][MX];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  VI d(n + 1), a(n);
  rep(i, n) cin >> d[i];
  rep(i, n) cin >> a[i];
  d[n] = l;
  constexpr int INF = 1001001001;
  rep(i, MX) rep(j, MX) dp[i][j] = INF;
  // (last sign, removed)
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    {  // move
      int len = d[i] - d[i - 1];
      for(int j = 0; j < i; j++) {
        for(int k = 0; k < MX; k++) if (dp[j][k] != INF) {
          dp[j][k] += a[j] * len;
        }
      }
    }
    if (i == n) break;
    rep(j, MX) rep(k, MX) ndp[j][k] = INF;
    {
      // next sign
      for(int j = 0; j < i; j++) {
        for(int k = 0; k < MX; k++) if (dp[j][k] != INF) {
          chmin(ndp[i][k], dp[j][k]);
          chmin(ndp[j][k+1], dp[j][k]);
        }
      }
    }
    rep(j, MX) rep(k, MX) dp[j][k] = ndp[j][k];
  }
  int ans = INF;
  rep(i, n) rep(j, k + 1) chmin(ans, dp[i][j]);
  cout << ans << '\n';
}