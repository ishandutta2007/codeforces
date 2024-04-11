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
    ll x;
    cin >> n >> x;
    constexpr long long INF = 1002003004005006007;
    int ans = 0;
    ll l = -INF, r = INF;
    rep(_, n) {
      ll a;
      cin >> a;
      chmax(l, a - x);
      chmin(r, a + x);
      if (!(l <= r)) {
        ans++;
        l = a - x, r = a + x;
      }
    }
    cout << ans << '\n';
  }
}