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
    int n, x, y;
    cin >> n >> x >> y;
    vector<char> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
      char c;
      cin >> c;
      a[i] ^= c;
    }
    {
      char c = 0;
      vector<char> na(n - 1);
      rep(i, n) {
        c ^= a[i];
        if (i < n - 1) na[i] = c;
      }
      if (c != 0) {
        cout << -1 << '\n';
        continue;
      }
      swap(na, a);
      n--;
    }
    // rep(i, n) cout << (int)a[i] << " \n"[i + 1 == n];
    constexpr long long INF = 1002003004005006007;
    VL dp[2], ndp[2];
    dp[0] = VL(n + 1, INF);
    dp[0][0] = 0;
    rep(i, n) {
      char ai = a[i];
      rep(i, 2) ndp[i].assign(n + 1, INF);
      rep(i, n + 1) if (ll v = dp[0][i]; v != INF) {
        rep(s, 2) {
          ll nv = v + s * x;
          chmin(ndp[(i ^ s ^ ai) & 1][i], nv);
        }
      }
      rep(z, 2) rrep(i, n) chmin(ndp[z][i], ndp[z][i+1]);
      rep(i, n) chmin(ndp[0][i+1], ndp[1][i] + y);
      rep(i, n - 1) if (ndp[0][i] != INF) chmin(ndp[0][i+2], ndp[0][i] + 2 * y);
      swap(dp, ndp);
      // cout << (int)ai << endl;
      // rep(i, n + 1) cout << dp[0][i] << " \n"[i + 1 == n + 1];
    }
    ll ans = dp[0][0];
    cout << ans << '\n';
    // exit(0);
  }
}