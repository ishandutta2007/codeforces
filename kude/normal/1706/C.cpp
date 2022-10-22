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
    VI h(n);
    rep(i, n) cin >> h[i];
    auto f = [&] {
      VL d(n + 1);
      for(int i = 3; i <= n; i += 2) {
        d[i] = d[i - 2] + max(0, max(h[i-3], h[i-1]) - h[i-2] + 1);
      }
      return d;
    };
    if (n & 1) {
      cout << f()[n] << '\n';
    } else {
      VL d1 = f();
      reverse(all(h));
      VL d2 = f();
      reverse(all(d2));
      constexpr long long INF = 1002003004005006007;
      ll ans = INF;
      for(int i = 1; i <= n; i += 2) chmin(ans, d1[i] + d2[i]);
      cout << ans << '\n';
    }
  }
}