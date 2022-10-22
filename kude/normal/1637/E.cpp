#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

template<class S>
struct value_compression : vector<S> {
  bool built = false;
  using VS = vector<S>;
  using VS::vector;
  value_compression(vector<S> v) : vector<S>(move(v)) {}
  void build() {
    sort(VS::begin(), VS::end());
    VS::erase(unique(VS::begin(), VS::end()), VS::end());
    built = true;
  }
  template<class T>
  void convert(T first, T last) { for (; first != last; ++first) *first = (*this)(*first); }
  int operator()(S x) {
    assert(built);
    return lower_bound(VS::begin(), VS::end(), x) - VS::begin();
  }
  void clear() { VS::clear(); built = false; }
};

bool fb[300010];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    VI a(n);
    rep(i, n) cin >> a[i];
    value_compression vc = a;
    vc.build();
    VVI forbidden(vc.size());
    rep(_, m) {
      int x, y;
      cin >> x >> y;
      int ix = vc(x);
      int iy = vc(y);
      forbidden[iy].emplace_back(ix);
    }
    VI cnt(vc.size());
    for(int ai: a) cnt[vc(ai)]++;
    value_compression<int> vccnt;
    for(int c: cnt) vccnt.emplace_back(c);
    vccnt.build();
    VVI hist_inv(vccnt.size());
    ll ans = -1;
    rep(iy, vc.size()) {
      const int y = vc[iy];
      const int cy = cnt[iy];
      for(int ix: forbidden[iy]) fb[ix] = true;

      rrep(icx, vccnt.size()) {
        const int cx = vccnt[icx];
        rrep(idx, hist_inv[icx].size()) {
          const int ix = hist_inv[icx][idx];
          if (fb[ix]) continue;
          const int x = vc[ix];
          chmax(ans, ll(cx + cy) * (x + y));
          break;
        }
      }
      hist_inv[vccnt(cnt[iy])].emplace_back(iy);

      for(int ix: forbidden[iy]) fb[ix] = false;
    }
    cout << ans << '\n';
  }
}