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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI m(n);
  VVI a(n);
  value_compression<int> vc;
  rep(i, n) {
    cin >> m[i];
    VI d(m[i]);
    rep(j, m[i]) cin >> d[j], vc.emplace_back(d[j]);
    a[i] = move(d);
  }
  vc.build();
  for(auto& ai : a) vc.convert(all(ai));

  VVI id;
  vector<P> id2idx;
  int nxt_id = 0;
  rep(i, n) {
    id.emplace_back(m[i]);
    rep(j, m[i]) {
      id[i][j] = nxt_id;
      id2idx.emplace_back(i, j);
      nxt_id++;
    }
  }

  int sz = vc.size();
  VI hist(sz);
  rep(i, n) rep(j, m[i]) hist[a[i][j]]++;
  rep(x, sz) if (hist[x] % 2) {
    cout << "NO\n";
    return 0;
  }
  VI pre(sz, -1);
  dsu d(nxt_id * 2);
  auto add = [&](int x, int y) {
    d.merge(x, nxt_id + y);
    d.merge(nxt_id + x, y);
  };
  rep(i, n) {
    rep(j, m[i]) {
      int x = a[i][j];
      if (pre[x] != -1) {
        add(pre[x], id[i][j]);
        pre[x] = -1;
      } else {
        pre[x] = id[i][j];
      }
    }
    for (int j = 0; j < m[i]; j += 2) {
      add(id[i][j], id[i][j + 1]);
    }
  }
  vector<string> ans;
  rep(i, n) ans.emplace_back(m[i], 'R');
  vector<char> visited(nxt_id);
  for (auto g : d.groups()) {
    if (visited[g[0] % nxt_id]) continue;
    for (int idx : g)  {
      if (idx < nxt_id) {
        visited[idx] = true;
        auto [i, j] = id2idx[idx];
        ans[i][j] = 'L';
      } else {
        visited[idx - nxt_id] = true;
      }
    }
  }
  cout << "YES\n";
  rep(i, n) cout << ans[i] << '\n';
}