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
    ll x;
    cin >> n >> x;
    VL a(n);
    rep(i, n) cin >> a[i];
    VL s(n + 1);
    rep(len, n + 1) {
      ll now = accumulate(a.begin(), a.begin() + len, 0LL);
      ll mx = now;
      rep(i, n - len) {
        now += a[i + len] - a[i];
        chmax(mx, now);
      }
      s[len] = mx;
    }
    rep(k, n + 1) {
      ll ans = 0;
      rep(len, n + 1) {
        chmax(ans, s[len] + max(min(k, len) * x, max(len - (n - k), 0) * x));
      }
      cout << ans << " \n"[k == n];
    }
  }
}