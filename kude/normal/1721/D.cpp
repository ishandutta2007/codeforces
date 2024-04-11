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
    VI a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    sort(all(a));
    sort(all(b));
    struct S { int la, ra, lb, rb; };
    vector<S> block_pairs{{0, n, 0, n}};
    int ans = 0;
    rrep(k, 30) {
      bool ok = true;
      for(auto [la, ra, lb, rb]: block_pairs) {
        int ca = -1, cb = -1;
        rep(_, 2) {
          sort(a.begin() + la, a.begin() + ra, [&](int x, int y) {
            return (x >> k & 1) < (y >> k & 1);
          });
          ca = lower_bound(a.begin() + la, a.begin() + ra, 1, [&](int x, int tgt) {
            return (x >> k & 1) < tgt;
          }) - a.begin();
          swap(a, b);
          swap(la, lb);
          swap(ca, cb);
          swap(ra, rb);
        }
        if (ca - la != rb - cb) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans |= 1 << k;
        vector<S> bs;
        for(auto [la, ra, lb, rb]: block_pairs) {
          int ca = lower_bound(a.begin() + la, a.begin() + ra, 1, [&](int x, int tgt) {
            return (x >> k & 1) < tgt;
          }) - a.begin();
          int cb = lower_bound(b.begin() + lb, b.begin() + rb, 1, [&](int x, int tgt) {
            return (x >> k & 1) < tgt;
          }) - b.begin();
          if (la < ca) bs.push_back({la, ca, cb, rb});
          if (ca < ra) bs.push_back({ca, ra, lb, cb});
        }
        swap(bs, block_pairs);
      }
    }
    cout << ans << '\n';
  }
}