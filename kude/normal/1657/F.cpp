#include<bits/stdc++.h>
namespace {
using namespace std;

#include <cassert>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {
namespace internal {

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct two_sat {
  public:
    two_sat() : _n(0), scc(0) {}
    explicit two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < _n);
        assert(0 <= j && j < _n);
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().second;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            _answer[i] = id[2 * i] < id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return _answer; }

  private:
    int _n;
    std::vector<bool> _answer;
    internal::scc_graph scc;
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
    std::vector<std::vector<int>> &to;
    int root, n;
    std::vector<int> sz, parent, depth, idx, ridx, head, inv;
    HLD(std::vector<std::vector<int>>& to, int root=0):
        to(to), root(root), n(to.size()),
        sz(n), parent(n), depth(n), idx(n), ridx(n), head(n), inv(n)
    {
        init_tree_data(root);
        int x = 0;
        assign_idx(root, root, x);
    }
    void init_tree_data(int u, int p=-1, int d=0) {
        parent[u] = p;
        depth[u] = d;
        int s = 1;
        for(int v: to[u]) {
            if (v == p) continue;
            init_tree_data(v, u, d+1);
            s += sz[v];
        }
        sz[u] = s;
    }
    void assign_idx(int u, int h, int &nxt, int p=-1) {
        head[u] = h;
        inv[nxt] = u;
        idx[u] = nxt++;
        if (sz[u] == 1) {
            ridx[u] = nxt;
            return;
        }
        int mxsize = 0;
        int mi;
        for(int v: to[u]) {
            if (v == p) continue;
            if (sz[v] > mxsize) {
                mxsize = sz[v];
                mi = v;
            }
        }
        assign_idx(mi, h, nxt, u);
        for(int v: to[u]) {
            if (v == p || v == mi) continue;
            assign_idx(v, v, nxt, u);
        }
        ridx[u] = nxt;
    }

    int lca(int u, int v) {
        while(head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) u = parent[head[u]];
            else v = parent[head[v]];
        }
        return (depth[u] < depth[v] ? u : v);
    }
    // returns (paths upto lca from x (excluding lca), those from y, lca)
    std::tuple<std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, int> paths(int x, int y) {
        std::tuple<std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, int> ret;
        std::vector<std::pair<int, int>>& x_paths = get<0>(ret);
        std::vector<std::pair<int, int>>& y_paths = get<1>(ret);
        int& lca = get<2>(ret);
        while(head[x] != head[y]) {
            int xhead = head[x], yhead = head[y];
            if (depth[xhead] > depth[yhead]) {
                x_paths.emplace_back(x, xhead);
                x = parent[xhead];
            } else {
                y_paths.emplace_back(y, yhead);
                y = parent[yhead];
            }
        }
        if (depth[x] > depth[y]) {
            int ychild = inv[idx[y] + 1];
            x_paths.emplace_back(x, ychild);
            x = y;
        } else if (depth[x] < depth[y]) {
            int xchild = inv[idx[x] + 1];
            y_paths.emplace_back(y, xchild);
            y = x;
        }
        lca = x;
        return ret;
    }
    
    int dist(int u, int v) {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};

bool falsified[400010][28];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  VVI to(n);
  rep(_, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    to[u].emplace_back(v);
    to[v].emplace_back(u);
  }
  HLD hld(to);
  two_sat ts(n * 26 + q);
  const int qb = n * 26;
  rep(_, q) {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    x--, y--;
    int c = hld.lca(x, y);
    VI path;
    while(x != c) {
      path.emplace_back(x);
      x = hld.parent[x];
    }
    path.emplace_back(c);
    int cur_sz = path.size();
    while(y != c) {
      path.emplace_back(y);
      y = hld.parent[y];
    }
    reverse(path.begin() + cur_sz, path.end());
    int sz = path.size();
    int qv = qb + _;
    rep(i, sz) {
      int c1 = s[i] - 'a', c2 = s[sz - 1 - i] - 'a';
      int v = path[i];
      rep(i, 26) {
        if (i != c1 && i != c2) {
          if (!falsified[v][i]) {
            ts.add_clause(26 * v + i, false, 26 * v + i, false);
            falsified[v][i] = true;
          }
          continue;
        }
      }
      if (c1 == c2) {
        ts.add_clause(26 * v + c1, true, 26 * v + c1, true);
      } else {
        ts.add_clause(qv, false, 26 * v + c1, true);
        ts.add_clause(qv, true,  26 * v + c2, true);
        ts.add_clause(26 * v + c1, false, 26 * v + c2, false);
        ts.add_clause(26 * v + c1, true, 26 * v + c2, true);
      }
    }
  }
  if (!ts.satisfiable()) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  auto assignment = ts.answer();
  string ans;
  rep(i, n) {
    bool done = false;
    rep(j, 26) if (assignment[26 * i + j]) {
      ans += 'a' + j;
      done = true;
      break;
    }
    if (!done) ans += 'a';
  }
  cout << ans << '\n';
}