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
  int cnt[5000];
  while(tt--) {
    int n;
    cin >> n;
    assert(n <= 5000);
    VI a(n);
    rep(i, n) cin >> a[i], a[i]--, assert(a[i] < n);
    
    int ans = 0;
    constexpr int INF = 1001001001;
    VI dp(n, -INF);
    {
      memset(cnt, 0, n * sizeof(int));
      int mx = 0;
      rep(i, n) {
        if (i % 2 == 0 && 2 * mx <= i) {
          dp[i] = 1;
        }
        chmax(mx, ++cnt[a[i]]);
      }
    }
    rep(i, n) if (dp[i] != -INF) {
      memset(cnt, 0, n * sizeof(int));
      int mx = 0;
      for (int j = i + 1; j < n; j++) {
        if (i % 2 != j % 2 && a[i] == a[j] && 2 * mx <= j - i - 1) {
          chmax(dp[j], dp[i] + 1);
        }
        chmax(mx, ++cnt[a[j]]);
      }
      if (n % 2 != i % 2 && 2 * mx <= n - i - 1) {
        chmax(ans, dp[i]);
      }
    }
    cout << ans << '\n';
  }
}