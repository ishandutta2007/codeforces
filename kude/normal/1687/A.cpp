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
    int n, k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    if (k >= n) {
      ans = accumulate(all(a), 0LL) + ll(k - 1) * n;
      ans -= (ll)n * (n - 1) / 2;
    } else {
      ll now = accumulate(a.begin(), a.begin() + k - 1, 0LL);
      rep(i, n - k + 1) {
        now += a[i + k - 1];
        chmax(ans, now);
        now -= a[i];
      }
      ans += (ll)k * (k - 1) / 2;
    }
    cout << ans << '\n';
  }
}