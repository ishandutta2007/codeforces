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
    rep(i, n) cin >> p[i];
    VI p_inv(n);
    rep(i, n) p_inv[p[i]] = i;
    int l = n, r = 0;
    ll ans = 1;
    rep(i, n - 1) {
      chmin(l, p_inv[i]);
      chmax(r, p_inv[i] + 1);
      int c1 = 0, c2 = 0;
      if (p_inv[i+1] < l) {
        c1 = l - p_inv[i+1] - 1;
        c2 = n - r;
      } else if (p_inv[i+1] >= r) {
        c1 = l;
        c2 = p_inv[i+1] - r;
      } else {
        continue;
      }
      int mxlen = (i + 1) * 2;
      if (r - l > mxlen) continue;
      int buf = mxlen - (r - l);
      chmin(c1, buf);
      chmin(c2, buf);
      if (c1 > c2) swap(c1, c2);
      if (c1 + c2 <= buf) {
        ans += ll(c1 + 1) * (c2 + 1);
        continue;
      }
      ans += ll(c1 + 1) * (buf - c1);
      int len = min(c2 - (buf - c1), c1);
      ans += ll(c1 + 1 + c1 + 1 - len) * (len + 1) / 2;
    }
    cout << ans << '\n';
  }
}