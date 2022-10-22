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
  using VS = vector<S>;
  using VS::vector;
  value_compression(vector<S> v) : vector<S>(move(v)) {}
  void build() {
    sort(VS::begin(), VS::end());
    VS::erase(unique(VS::begin(), VS::end()), VS::end());
  }
  template<class T>
  void convert(T first, T last) { for (; first != last; ++first) *first = (*this)(*first); }
  int operator()(S x) {
    auto it = lower_bound(VS::begin(), VS::end(), x);
    if (it == VS::end() || *it != x) return -1;
    return it - VS::begin();
  }
  void clear() { VS::clear(); }
};

std::vector<long long> divisors(long long x) {
    std::vector<long long> res1, res2;
    long long d = 1;
    for(; d * d < x; d++) {
        if (x % d == 0) {
            res1.push_back(d);
            res2.push_back(x / d);
        }
    }
    if (d * d == x) res1.push_back(d);
    int sz = res2.size();
    res1.reserve(res1.size() + sz);
    for(int i = sz - 1; i >= 0; i--) res1.push_back(res2[i]);
    return res1;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int x, d;
    cin >> x >> d;
    value_compression<ll> divs = divisors(x);
    VL ds;
    for(ll di: divs) if (di % d == 0 && di % ll(d * d) != 0) ds.emplace_back(di);
    int sz = divs.size();
    VI dp(sz);
    dp[0] = 1;
    for(ll di: ds) {
      rep(i, sz) {
        ll v = divs[i] * di;
        if (v > x) break;
        int iv = divs(v);
        if (iv == -1) continue;
        dp[iv] += dp[i];
        chmin(dp[iv], 2);
      }
    }
    cout << (dp[sz - 1] >= 2 ? "YES\n" : "NO\n");
  }
}