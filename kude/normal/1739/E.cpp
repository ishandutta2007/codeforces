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
    string s[2];
    int tot = 0;
    rep(i, 2) {
      cin >> s[i];
      rep(j, n) tot += s[i][j] - '0';
      s[i].insert(s[i].begin(), '0');
      s[i] += '0';
    }
    n += 2;
    constexpr int INF = 1001001001;
    int dp[4][2];
    rep(i, 4) rep(j, 2) dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i = 0; i + 1 < n; i++) {
      int ndp[4][2];
      rep(i, 4)  rep(j,2) ndp[i][j] = INF;
      int v = (s[0][i+1] - '0') | (s[1][i+1] - '0') << 1;
      rep(i, 4) rep(j, 2) if (dp[i][j] != INF) {
        if (i) {
          chmin(ndp[0][j ^ 1], dp[i][j] + (v >> j & 1));
        } else {
          chmin(ndp[v & ~(1 << j)][j], dp[i][j]);
          chmin(ndp[0][j], dp[i][j] + (v >> (1 ^ j) & 1));
        }
      }
      memcpy(dp, ndp, sizeof(ndp));
    }
    int ans = min(dp[0][0], dp[0][1]);
    cout << tot - ans << '\n';
  }
}