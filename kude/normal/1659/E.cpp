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
  int n, m;
  cin >> n >> m;
  vector<char> has_zero(n);
  vector<tuple<int, int, int>> es(m);
  for(auto& [a, b, w]: es) {
    cin >> a >> b >> w;
    a--, b--;
    if (w % 2 == 0) has_zero[a] = has_zero[b] = true;
  }
  vector<dsu> bit_connected;
  rep(k, 30) {
    dsu d(n);
    for(auto [a, b, w]: es) if (w >> k & 1) d.merge(a, b);
    bit_connected.emplace_back(move(d));
  }
  vector<char> ok1(n);
  for(int k = 1; k < 30; k++) {
    dsu d(n);
    for(auto [a, b, w]: es) if (w >> k & 1) d.merge(a, b);
    for(const auto& g: d.groups()) {
      bool ok = false;
      for(int v: g) if (has_zero[v]) {
        ok = true;
        break;
      }
      if (ok) for(int v: g) ok1[v] = true;
    }
  }

  auto conn_check = [&](int u, int v) {
    rep(k, 30) if (bit_connected[k].same(u, v)) return true;
    return false;
  };
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int ans = 2;
    if (conn_check(u, v)) ans = 0;
    else if (ok1[u]) ans = 1;
    cout << ans << '\n';
  }
}