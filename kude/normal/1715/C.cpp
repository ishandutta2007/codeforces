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
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    VI a(n);
    rep(i, n) cin >> a[i];
    ll ans = (ll)(n + 1) * n / 2;
    auto cost = [&](int i) -> ll {
      if (!(0 <= i && i < n - 1)) return 0;
      if (a[i] == a[i + 1]) return 0;
      return ll(i + 1) * (n - i - 1);
    };
    rep(i, n) ans += cost(i);
    while(m--) {
      int i, x;
      cin >> i >> x;
      i--;
      ans -= cost(i);
      ans -= cost(i - 1);
      a[i] = x;
      ans += cost(i);
      ans += cost(i - 1);
      cout << ans << '\n';
    }
  }
}