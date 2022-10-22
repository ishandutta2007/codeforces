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

ll isqrt(ll x2) {
  if (x2 == 0) return 0;
  ll x = x2;
  while(true) {
    ll nx = (x + x2 / x) / 2;
    if (x <= nx) return x;
    x = nx;
  }
}

ll dp[1000100];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // t*dx=H
  // t*D<h
  // t=H/dx
  // H/dx*D<h
  // HD<hdx
  memset(dp, -1, sizeof(dp));
  int n, C;
  cin >> n >> C;
  rep(i, n) {
    int c, d, h;
    cin >> c >> d >> h;
    chmax(dp[c], (ll)d * h);
  }
  for(int c = 1; c < C; c++) if (dp[c] != -1) {
    for(int d = c + c, k = 2; d <= C; d += c, k++) {
      chmax(dp[d], k * dp[c]);
    }
  }
  rep(i, C) chmax(dp[i + 1], dp[i]);
  int m;
  cin >> m;
  rep(i, m) {
    ll h, d;
    cin >> h >> d;
    ll hd = h * d;
    ll ans = -1;
    if (dp[C] > hd) {
      int l = 0, r = C;
      while(r - l > 1) {
        int c = (l + r) / 2;
        if (dp[c] > hd) {
          r = c;
        } else {
          l = c;
        }
      }
      ans = r;
    }
    cout << ans << " \n"[i + 1 == m];
  }
}