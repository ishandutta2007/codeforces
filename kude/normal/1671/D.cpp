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
    int n, x;
    cin >> n >> x;
    VI a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n - 1) ans += abs(a[i] - a[i+1]);
    {
      int res = min(a[0] - 1, a[n - 1] - 1);
      rep(i, n - 1) chmin(res, 2 * (min(a[i], a[i + 1]) - 1));
      ans += res;
    }
    if (x > *max_element(all(a))) {
      int res = min(x - a[0], x - a[n - 1]);
      rep(i, n - 1) chmin(res, 2 * (x - max(a[i], a[i + 1])));
      ans += res;
    }
    cout << ans << '\n';
  }
}