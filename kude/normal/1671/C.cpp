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
    int n, x;
    cin >> n >> x;
    VI a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    VL s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    VL d(n + 1);
    for (int i = 1; i <= n; i++) {
      if (x < s[i]) break;
      d[i] = (x - s[i]) / i + 1;
    }
    for (int i = 1; i < n; i++) d[i] -= d[i + 1];
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans += d[i] * i;
    cout << ans << '\n';
  }
}