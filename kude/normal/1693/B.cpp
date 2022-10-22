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
    VI p(n);
    p[0] = -1;
    rep(i, n - 1) cin >> p[i + 1], p[i + 1]--;
    VI l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];
    VL dp(n);
    int ans = 0;
    rrep(i, n) {
      chmin<ll>(dp[i], r[i]);
      if (dp[i] < l[i]) {
        ans++;
        dp[i] = r[i];
      }
      if (i) dp[p[i]] += dp[i];
    }
    cout << ans << '\n';
  }
}