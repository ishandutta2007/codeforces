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
    int n, k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    ll ans = -1;
    VL s(n + 1);
    VI cnt(n + 1);
    rep(_, 2) {
      rep(i, n) s[i+1] = s[i] + a[i];
      rep(i, n) cnt[i+1] = cnt[i] + (a[i] == 0);
      ll req = -s[n];
      if (abs(req) > (ll)k * cnt[n]) break;
      rep(imx, n + 1) rep(imn, imx + 1) {
        int cf = cnt[imn] + cnt[n] - cnt[imx];
        int cx = cnt[imx] - cnt[imn];
        ll lf = (ll)-k * cf, rf = -lf;
        ll lx = (ll)-k * cx, rx = -lx;
        ll diff = s[imx] - s[imn];
        ll fix = req;
        if (fix >= 0) {
          ll v = min(fix, rx);
          diff += v;
          fix -= v, lx -= v, rx -= v;
          lf -= fix, rf -= fix;
        } else {
          ll v = max(fix, lf);
          fix -= v, lf -= v, rf -= v;
          diff += fix;
          lx -= fix, rx -= fix;
        }
        diff += min(rx, -lf);
        chmax(ans, diff + 1);
      }
      for(int& x: a) x = -x;
    }
    cout << ans << '\n';
  }
}