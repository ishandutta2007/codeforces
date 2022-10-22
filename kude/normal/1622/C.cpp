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
    ll k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    sort(rall(a));
    int mn = a.back(); a.pop_back();
    VL s(n);
    rep(i, n - 1) s[i + 1] = s[i] + a[i];
    ll ans = 2001001001;
    rep(i, n) {
      ll x = s[n - 1] + mn - (s[i] - (ll)i * mn) - k;
      // cout << i << ' ' << x << ' ' << s[i] << ' ' << mn << ' ' << a[0] << endl;
      if (x <= 0) {
        chmin<ll>(ans, i);
        break;
      }
      chmin(ans, (x + i) / (i + 1) + i);
    }
    cout << ans << '\n';
  }
}