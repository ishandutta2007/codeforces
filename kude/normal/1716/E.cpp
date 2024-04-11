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

struct S { ll sm, mn, mx, res; };
S op(S x, S y) {
  y.mn += x.sm;
  y.mx += x.sm;
  return {x.sm + y.sm, min(x.mn, y.mn), max(x.mx, y.mx),
          max({x.res, y.res, y.mx - x.mn})};
}

S d[1 << 18];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  rep(i, 1 << n) {
    int a;
    cin >> a;
    ll mn = 0, mx = 0;
    (a > 0 ? mx : mn) = a;
    d[i] = {a, mn, mx, mx};
  }
  rep(k, n) {
    const int k2 = 1 << k;
    rrep(i, 1 << n) {
      i &= ~k2;
      S r0 = op(d[i], d[i + k2]);
      S r1 = op(d[i + k2], d[i]);
      d[i] = r0;
      d[i + k2] = r1;
    }
  }
  int x = 0;
  int q;
  cin >> q;
  while(q--) {
    int k;
    cin >> k;
    x ^= 1 << k;
    cout << d[x].res << '\n';
  }
}