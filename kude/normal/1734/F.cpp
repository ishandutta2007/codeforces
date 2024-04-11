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
    ll n, m;
    cin >> n >> m;
    // popcount i ^ (i + n), carry of i + n, i >= m
    ll dp[2][2][2] = {};
    dp[0][0][1] = 1;
    rep(k, 62) {
      int x = n >> k & 1;
      int mk = m >> k & 1;
      ll ndp[2][2][2] = {};
      rep(p, 2) rep(c, 2) rep(d, 2) {
        ll val = dp[p][c][d];
        rep(ix, 2) {
          int sm = c + ix + x;
          int np = p ^ ix ^ (sm & 1);
          int nc = sm >> 1;
          int nd = ix == mk ? d : ix > mk;
          ndp[np][nc][nd] += val;
        }
      }
      memcpy(dp, ndp, sizeof(ndp));
    }
    ll ans = dp[1][0][0];
    cout << ans << '\n';
  }
}