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

int dp[510][510];
int d[510][510];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI a(n);
  rep(i, n) cin >> a[i];
  rep(i, 510) rep(j, 510) dp[i][j] = -1;
  dp[0][1] = a[0];
  dp[1][0] = a[1];
  for(int i = 1; i < n; i++) {
    rep(j, 510) rep(k, 510) d[j][k] = -1;
    rep(j, 510) rep(k, 510) if (int v = dp[j][k]; v != -1) {
      int p = i, q = k + 1;
      if (j >= i) {
        int add = j + 1 - p;
        p += add;
        q -= add;
      }
      if (p < n && q >= 0) chmax(d[p][q], v);
    }
    rep(j, 510) rep(k, 510) if (d[j][k] != -1) {
      chmax(dp[j][k], d[j][k]);
      if (k) chmax(d[j+1][k-1], d[j][k]);
    }
    rep(j, n) rep(k, 510) if (dp[j][k] != -1) dp[j][k] += a[j];
  }
  int ans = 0;
  rep(j, n) rep(k, 510) chmax(ans, dp[j][k]);
  cout << ans << '\n';
}