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
    VI a(n);
    rep(i, n) cin >> a[i];
    int mx = *max_element(all(a));
    constexpr ll INF = 1002003004005006007;
    ll ans = INF;
    for(int t: {mx, mx + 1}) {
      ll c1 = 0, c2 = 0;
      rep(i, n) {
        int x = t - a[i];
        c1 += x & 1;
        c2 += x >> 1;
      }
      ll l = -1, r = INF;
      while(r - l > 1) {
        ll c = (l + r) / 2;
        ll cnt1 = (c + 1) / 2, cnt2 = c - cnt1;
        if (cnt1 < c1) {
          l = c;
          continue;
        }
        cnt1 -= c1;
        cnt2 += cnt1 / 2;
        if (cnt2 < c2) l = c;
        else r = c;
      }
      chmin(ans, r);
    }
    cout << ans << '\n';
  }
}