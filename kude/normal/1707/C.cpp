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

struct HLD {
  const vector<vector<int>>& to;
  int root, n;
  vector<int> sz, parent, depth, idx, ridx, head, inv;

  HLD(const vector<vector<int>>& to, int root=0)
      : to(to), root(root), n(to.size()),
        sz(n), parent(n), depth(n), idx(n), ridx(n), head(n), inv(n) {
    init_tree_data(root, -1, 0);
    int nxt = 0;
    assign_idx(root, root, nxt);
  }
  void init_tree_data(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    int s = 1;
    for (int v: to[u]) if (v != p) {
      init_tree_data(v, u, d+1);
      s += sz[v];
    }
    sz[u] = s;
  }
  void assign_idx(int u, int h, int& nxt, int p=-1) {
    head[u] = h;
    idx[u] = nxt;
    inv[nxt] = u;
    nxt++;
    int heaviest = -1;
    int mxweight = 0;
    for (int v: to[u]) if (v != p) {
      if (sz[v] > mxweight) {
        heaviest = v;
        mxweight = sz[v];
      }
    }
    if (heaviest != -1) {
      assign_idx(heaviest, h, nxt, u);
      for (int v: to[u]) if (v != p && v != heaviest) {
        assign_idx(v, v, nxt, u);
      }
    }
    ridx[u] = nxt;
  }

  int lca(int u, int v) {
    while (head[u] != head[v]) {
      if (depth[head[u]] > depth[head[v]]) {
        u = parent[head[u]];
      } else {
        v = parent[head[v]];
      }
    }
    return depth[u] < depth[v] ? u : v;
  }
  // returns reference to tuple of (path fragments from x upto lca (excluding lca), those from y, lca)
  // storage of retval is reused to avoid creating short vectors on each query
  tuple<vector<pair<int, int>>, vector<pair<int, int>>, int> paths_res;
  auto& paths(int x, int y) {
    auto& [x_paths, y_paths, lca] = paths_res;
    x_paths.clear();
    y_paths.clear();
    while (head[x] != head[y]) {
      int hx = head[x], hy = head[y];
      if (depth[hx] > depth[hy]) {
        x_paths.emplace_back(x, hx); x = parent[hx];
      } else {
        y_paths.emplace_back(y, hy); y = parent[hy];
      }
    }
    if (depth[x] > depth[y]) {
      x_paths.emplace_back(x, inv[idx[y] + 1]); x = y;
    } else if (depth[x] < depth[y]) {
      y_paths.emplace_back(y, inv[idx[x] + 1]); y = x;
    }
    lca = x;
    return paths_res;
  }
  int dist(int u, int v) {
    int w = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
  }
  template <class F> int max_ancestor(int v, F f) {
    if (!f(v)) return -1;
    int hv = head[v];
    int p = parent[hv];
    while (p != -1 && f(p)) {
      v = p;
      hv = head[v];
      p = parent[hv];
    }
    int il = idx[hv] - 1, ir = idx[v];
    while (ir - il > 1) {
      int ic = (il + ir) / 2;
      (f(inv[ic]) ? ir : il) = ic;
    }
    return inv[ir];
  }
  int ascend(int v, int k) {
    assert(depth[v] >= k);
    int td = depth[v] - k;
    int hv = head[v];
    while (depth[hv] > td) {
      v = parent[hv];
      hv = head[v];
    }
    int rest = depth[v] - td;
    return inv[idx[v] - rest];
  }
};


} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<P> es(m);
    for(auto& [u, v]: es) {
      cin >> u >> v;
      u--, v--;
    }
    dsu uf(n);
    VVI to1(n), to2(n);
    int tot = 0;
    rep(i, m) {
      auto [u, v] = es[i];
      if (uf.same(u, v)) {
        to2[u].emplace_back(v);
        tot++;
      } else {
        uf.merge(u, v);
        to1[u].emplace_back(v);
        to1[v].emplace_back(u);
      }
    }
    HLD hld(to1);
    VI d(n);
    rep(u, n) for(int v: to2[u]) {
      int c = hld.lca(u, v);
      bool swp = c == u;
      if (swp) swap(u, v);
      if (c == v) {
        d[u]++;
        d[0]++;
        int k = hld.depth[u] - hld.depth[v];
        d[hld.ascend(u, k - 1)]--;
      } else {
        d[u]++;
        d[v]++;
      }
      if (swp) swap(u, v);
    }
    rep(i, n) {
      int u = hld.inv[i];
      for(int v: to1[u]) if (v != hld.parent[u]) {
        d[v] += d[u];
      }
    }
    string ans(n, '0');
    rep(i, n) if (d[i] == tot) ans[i] = '1';
    cout << ans << '\n';
  }
}