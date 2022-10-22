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
    int n;
    cin >> n;
    VI a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 1002003004005006007;
    rep(_, 2) {
      ll v = 0;
      rep(_, 2) {
        ll s = 0;
        rep(_, 2) {
          ll mn = 1002003004005006007;
          rep(i, n) chmin(mn, (ll)abs(b[i] - a[0]));
          s += mn;
          swap(a, b);
        }
        v += min(s, (ll)abs(a[0] - b[0]));
        reverse(all(a));
        reverse(all(b));
      }
      chmin(ans, v);
      reverse(all(b));
    }
    cout << ans << '\n';
  }
}