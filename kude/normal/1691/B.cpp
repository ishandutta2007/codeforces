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
    value_compression vc = a;
    vc.build();
    vc.convert(all(a));
    int sz = vc.size();
    VVI d(sz);
    rep(i, n) d[a[i]].emplace_back(i);
    bool ok = true;
    rrep(i, sz) if ((int)d[i].size() == 1) {
      ok = false;
      break;
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    VI ans(n);
    rrep(i, sz) {
      int t = d[i].size();
      rep(j, t) ans[d[i][j]] = d[i][(j+1) % t];
    }
    rep(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  }
}