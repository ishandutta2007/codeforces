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
    int n, s;
    cin >> n >> s;
    VI a(n);
    rep(i, n) cin >> a[i];
    int now = 0;
    int r = 0;
    constexpr int INF = 1001001001;
    int mx = -INF;
    rep(i, n) {
      chmax(r, i);
      while(r < n && now + a[r] <= s) now += a[r++];
      if (now == s) chmax(mx, r - i);
      if (i < r) now -= a[i];
    }
    if (mx == -INF) {
      cout << -1 << '\n';
    } else {
      cout << n - mx << '\n';
    }
  }
}