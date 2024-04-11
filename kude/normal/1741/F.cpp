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
    struct S {
      int i, l, r, c;
    };
    vector<S> a(n);
    rep(i, n) {
      int l, r, c;
      cin >> l >> r >> c;
      a[i] = {i, l, r, c};
    }
    constexpr long long LINF = 1002003004005006007;
    constexpr int INF = 1001001001;
    VL ans(n, LINF);
    rep(_, 2) {
      sort(all(a), [](const S& x, const S& y) {
        if (x.l != y.l) return x.l < y.l;
        if (x.r != y.r) return x.r > y.r;
        return x.i < y.i;
      });
      struct RC {
        ll r;
        int c;
      };
      RC rmx[2];
      rmx[0] = {-INF, -1};
      rmx[1] = {-INF, -2};
      for(auto [i, l, r, c]: a) {
        // cout << "aa" << i << ' ' << l << ' ' << r << ' ' << c << endl;
        if (c != rmx[0].c) chmin(ans[i], max(0LL, l - rmx[0].r));
        else chmin(ans[i], max(0LL, l - rmx[1].r));
        if (c == rmx[0].c) {
          if (r >= rmx[0].r) rmx[0] = {r, c};
        } else {
          if (r >= rmx[0].r) rmx[1] = rmx[0], rmx[0] = {r, c};
          else if (r >= rmx[1].r) rmx[1] = {r, c};
        }
      }
      sort(all(a), [](const S& x, const S& y) {
        if (x.r != y.r) return x.r < y.r;
        if (x.l != y.l) return x.l > y.l;
        return x.i > y.i;
      });
      rmx[0] = {-INF, -1};
      rmx[1] = {-INF, -2};
      for(auto [i, l, r, c]: a) {
        if (c != rmx[0].c) chmin(ans[i], max(0LL, l - rmx[0].r));
        else chmin(ans[i], max(0LL, l - rmx[1].r));
        if (c == rmx[0].c) {
          if (r >= rmx[0].r) rmx[0] = {r, c};
        } else {
          if (r >= rmx[0].r) rmx[1] = rmx[0], rmx[0] = {r, c};
          else if (r >= rmx[1].r) rmx[1] = {r, c};
        }
      }
      for(auto& [i, l, r, c]: a) {
        int nl = 1000000000 - r;
        int nr = 1000000000 - l;
        l = nl, r = nr;
      }
    }
    rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
  }
}