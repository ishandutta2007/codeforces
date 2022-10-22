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

int a[1000][1000];
int dp[1000][1000];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> a[i][j];
    if ((n + m - 1) % 2) {
      cout << "NO\n";
      continue;
    }
    constexpr int INF = 1001001001;
    rep(i, n) rep(j, m) dp[i][j] = -INF;
    dp[0][0] = 0;
    rep(i, n) rep(j, m) {
      dp[i][j] += a[i][j];
      if (i + 1 < n) chmax(dp[i+1][j], dp[i][j]);
      if (j + 1 < m) chmax(dp[i][j+1], dp[i][j]);
    }
    int mx = dp[n-1][m-1];
    rep(i, n) rep(j, m) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, n) rep(j, m) {
      dp[i][j] += a[i][j];
      if (i + 1 < n) chmin(dp[i+1][j], dp[i][j]);
      if (j + 1 < m) chmin(dp[i][j+1], dp[i][j]);
    }
    int mn = dp[n-1][m-1];
    cout << (mn <= 0 && 0 <= mx ? "YES\n" : "NO\n");
  }
}