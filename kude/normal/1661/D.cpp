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
  int n, k;
  cin >> n >> k;
  VL b(n);
  rep(i, n) cin >> b[i];
  VL d1(n), d2(n);
  ll s = 0, t = 0;
  // y = sx + t
  ll ans = 0;
  rrep(x, n) {
    s += d1[x];
    t += d2[x];
    ll y = s * x + t;
    ll dy = b[x] - y;
    if (dy <= 0) continue;
    int xp = max(0, x - k + 1);
    int unit = x - xp + 1;
    ll cnt = (dy + unit - 1) / unit;
    ans += cnt;
    s += cnt;
    t += -(xp - 1) * cnt;
    if (xp) {
      d1[xp - 1] -= cnt;
      d2[xp - 1] -= -(xp - 1) * cnt;
    }
  }
  cout << ans << '\n';
}