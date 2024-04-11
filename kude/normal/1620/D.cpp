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

int a[100];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    constexpr int INF = 1001001001;
    int ans = INF;
    int dp[33];
    rep(i1, 10) rep(i2, 10) {
      int mx = i1 + 2 * i2;
      rep(i, mx + 1) dp[i] = -1;
      dp[0] = 0;
      rep(c1, i1 + 1) rep(c2, i2 + 1) {
        int x = c1 + 2 * c2;
        dp[x] = x;
      }
      rep(i, mx - 2) chmax(dp[i + 3], dp[i]);
      int r[3] = {-1, -1, -1};
      rep(i, mx + 1) chmax(r[i % 3], dp[i]);

      bool ok = true;
      int i3 = 0;
      rep(i, n) {
        int x = a[i];
        int t;
        if (x <= mx) t = dp[x];
        else t = r[x % 3];
        if (t == -1) {
          ok = false;
          break;
        }
        x -= t;
        chmax(i3, x / 3);
      }
      if (ok) chmin(ans, i1 + i2 + i3);
    }
    cout << ans << '\n';
  }
}