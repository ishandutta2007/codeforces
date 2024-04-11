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

template<class T>
T isqrt(T x) {
  assert(x >= 0);
  if (x <= 1) return x;
  T r = x >> 1;
  while(true) {
    T nr = (r + x / r) >> 1;
    if (r <= nr) break;
    r = nr;
  }
  return r;
}

ll f(ll r) {
  ll sr = isqrt(r);
  ll res = 3 * (sr - 1);
  rep(i, 3) res += sr * (i + sr) < r;
  return res;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    ll l, r;
    cin >> l >> r;
    ll ans = f(r+1) - f(l);
    cout << ans << '\n';
  }
}