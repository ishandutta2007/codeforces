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

ll dp[5001];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int p1, p2;
  ll t1, t2;
  cin >> p1 >> t1 >> p2 >> t2;
  int h, s;
  cin >> h >> s;
  constexpr long long INF = 1002003004005006007;
  rep(i, h + 1) dp[i] = INF;
  dp[h] = 0;
  ll ans = INF;
  rrep(i, h + 1) {
    if (i == 0) {
      chmin(ans, dp[i]);
      break;
    }
    {
      ll l = 0, r = INF;
      while(r - l > 1) {
        ll c = (l + r) / 2;
        ll d1, d2;
        if (__builtin_mul_overflow(c / t1, p1 - s, &d1)) d1 = INF;
        if (__builtin_mul_overflow(c / t2, p2 - s, &d2)) d2 = INF;
        ll d = d1 + d2;
        (d >= i ? r : l) = c;
      }
      chmin(ans, dp[i] + r);
    }
    rep(_, 2) {
      for(ll k = max(1LL, (t2 + t1 - 1) / t1);; k++) {
        ll time = t1 * k;
        ll life = i;
        ll c1 = time / t1;
        ll c2 = time / t2;
        life -= (c1 - 1) * (p1 - s);
        life -= (c2 - 1) * (p2 - s);
        life -= (p1 + p2 - s);
        if (life <= 0) {
          chmin(ans, dp[i] + time);
          break;
        }
        chmin(dp[life], dp[i] + time);
      }
      swap(p1, p2);
      swap(t1, t2);
    }
  }
  cout << ans << '\n';
}