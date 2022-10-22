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


struct HLD {
  const vector<vector<int>> &to;
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
    for(int v: to[u]) if (v != p) {
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
    for(int v: to[u]) if (v != p) {
      if (sz[v] > mxweight) {
        heaviest = v;
        mxweight = sz[v];
      }
    }
    if (heaviest != -1) {
      assign_idx(heaviest, h, nxt, u);
      for(int v: to[u]) if (v != p && v != heaviest) {
        assign_idx(v, v, nxt, u);
      }
    }
    ridx[u] = nxt;
  }

  int lca(int u, int v) {
    while(head[u] != head[v]) {
      if (depth[head[u]] > depth[head[v]]) {
        u = parent[head[u]];
      } else {
        v = parent[head[v]];
      }
    }
    return depth[u] < depth[v] ? u : v;
  }
  // returns reference to tuple of (path fragments from x upto lca (excluding lca), those from y, lca)
  // return value is reused so that small vectors are not created on each query
  tuple<vector<pair<int, int>>, vector<pair<int, int>>, int> paths_res;
  auto& paths(int x, int y) {
    auto& [x_paths, y_paths, lca] = paths_res;
    x_paths.clear();
    y_paths.clear();
    while(head[x] != head[y]) {
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
    while(p != -1 && f(p)) {
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
    while(depth[hv] > td) {
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
    int n;
    cin >> n;
    VVI to(n);
    rep(i, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v);
      to[v].emplace_back(u);
    }
    HLD hld(to);
    int q;
    cin >> q;
    VI p;
    vector<char> used;
    while(q--) {
      int k;
      cin >> k;
      p.resize(k);
      used.assign(k, false);
      rep(i, k) cin >> p[i], p[i]--;
      sort(all(p), [&](int i, int j) {
        return hld.depth[i] > hld.depth[j];
      });
      int u = p[0], preu = -1;
      used[0] = true;
      for (int i = 1; i < k; i++) {
        int k = hld.depth[u] - hld.depth[p[i]];
        if (k == 0) continue;
        int npreu = hld.ascend(u, k - 1);
        int c = hld.parent[npreu];
        if (p[i] == c) {
          used[i] = true;
          u = c;
          preu = npreu;
        }
      }
      bool ok = true;
      int v = -1;
      rep(i, k) if (!used[i]) {
        if (v == -1) {
          v = p[i];
          continue;
        }
        int k = hld.depth[v] - hld.depth[p[i]];
        int c = hld.ascend(v, k);
        if (c != p[i]) {
          ok = false;
          break;
        }
        v = c;
      }
      if (v != -1 && preu != -1) {
        int c = hld.lca(preu, v);
        if (c == preu) ok = false;
      }
      cout << (ok ? "YES\n" : "NO\n");
    }
  }
}