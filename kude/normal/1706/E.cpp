#include<bits/stdc++.h>
namespace {
using namespace std;

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace atcoder;
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<P> es(m);
    for(auto& [a, b]: es) {
      cin >> a >> b;
      a--; b--;
    }
    vector<P> qs(q);
    for(auto& [a, b]: qs) {
      cin >> a >> b;
      a--;
    }
    VI l(q, 0), r(q, m);
    rep(i, q) if (qs[i].first + 1 == qs[i].second) {
      r[i] = 0;
    }
    VI set_init(n);
    rep(i, n) set_init[i] = i + 1;
    while(true) {
      bool all_done = true;
      VVI qids(m + 1);
      rep(i, q) if (r[i] - l[i] > 1) {
        int ci = (r[i] + l[i]) / 2;
        qids[ci].emplace_back(i);
        all_done = false;
      }
      if (all_done) break;
      set<int> st(all(set_init));
      dsu d(n);
      rep(i, m) {
        auto [a, b] = es[i];
        d.merge(a, b);
        for(int qi: qids[i + 1]) {
          auto [li, ri] = qs[qi];
          auto it = st.upper_bound(li);
          bool ok = true;
          while(*it < ri) {
            if (d.same(*it - 1, *it)) {
              it = st.erase(it);
            } else {
              ok = false;
              break;
            }
          }
          (ok ? r[qi] : l[qi]) = i + 1;
        }
      }
    }
    rep(i, q) cout << r[i] << " \n"[i + 1 == q];
  }
}