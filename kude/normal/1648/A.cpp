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
  int tt = 1;
  // cin >> tt;
  value_compression<int> vc; vc.reserve(100000);
  while(tt--) {
    vc.clear();
    int n, m;
    cin >> n >> m;
    VVI a(n, VI(m));
    rep(i, n) rep(j, m) cin >> a[i][j], vc.emplace_back(a[i][j]);
    vc.build();
    rep(i, n) vc.convert(all(a[i]));
    int mx = vc.size();
    VI cnt(mx);
    VL sm(mx);
    ll ans = 0;
    rep(i, n) {
      rep(j, m) {
        int x = a[i][j];
        ans += (ll)i * cnt[x] - sm[x];
      }
      rep(j, m) {
        int x = a[i][j];
        cnt[x]++;
        sm[x] += i;
      }
    }
    rep(x, mx) cnt[x] = 0, sm[x] = 0;
    rep(j, m) {
      rep(i, n) {
        int x = a[i][j];
        ans += (ll)j * cnt[x] - sm[x];
      }
      rep(i, n) {
        int x = a[i][j];
        cnt[x]++;
        sm[x] += j;
      }
    }
    cout << ans << '\n';
  }
}