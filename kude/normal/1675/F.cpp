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


vector<int> euler_tour_vertices(const vector<vector<int>>& tree, int root=0) {
  const int n = tree.size();
  assert(n > 0);
  vector<int> res;
  res.reserve(2 * n - 1); // 1 + 2|E|
  res.emplace_back(root);
  vector<pair<int, int>> st;
  st.reserve(n);
  st.emplace_back(root, 0);
  while(!st.empty()) {
    auto& [u, i] = st.back();
    if (i == (int)tree[u].size()) {
      st.pop_back();
      if (!st.empty()) res.emplace_back(st.back().first);
    } else {
      int v = tree[u][i++];
      const int sz = st.size();
      if (sz >= 2 && v == st[sz - 2].first) continue;
      st.emplace_back(v, 0);
      res.emplace_back(v);
    }
  }
  return res;
}

template <class S, S (*op)(S, S), S (*e)()> struct SparseTable {
  int n;
  vector<int> floor_lg;
  vector<vector<S>> d;
  SparseTable() {}
  explicit SparseTable(vector<S>&& a): n(a.size()), floor_lg(n + 1) {
    if (n == 0) return;
    int frog = 0;
    for(int i = 1; i <= n; frog++) {
      int j = min(n + 1, 2 * i);
      for(; i < j; i++) floor_lg[i] = frog;
    }
    d.resize(frog);
    d[0] = move(a);
    for(int p = 0, w = 1; p < frog - 1; p++, w *= 2) {
      int last = n - 2 * w;
      d[p + 1].resize(last + 1);
      for(int i = 0; i <= last; i++) d[p + 1][i] = op(d[p][i], d[p][i + w]);
    }
  }
  explicit SparseTable(const vector<S>& a): SparseTable(vector<S>(a)) {}

  S query(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return e();
    int w = r - l;
    int p = floor_lg[w];
    return op(d[p][l], d[p][r - (1 << p)]);
  }
};

struct IdxDepth { int i, d; };
IdxDepth op_idx_depth(IdxDepth x, IdxDepth y) { return x.d < y.d ? x : y; }
IdxDepth e_idx_depth() { return {-1, numeric_limits<int>::max()}; }

struct LCA {
  using RmQ = SparseTable<IdxDepth, op_idx_depth, e_idx_depth>;
  const int n;
  vector<int> depth;
  const vector<int> tour;
  vector<int> pos;
  RmQ rmq;
  LCA(const vector<vector<int>>& tree, int root=0)
      : n(tree.size()), depth(n, -1), tour(euler_tour_vertices(tree, root)), pos(n) {
    vector<int> st{root};
    st.reserve(n);
    depth[root] = 0;
    while(!st.empty()) {
      int u = st.back(); st.pop_back();
      for(int v: tree[u]) {
        if (depth[v] == -1) {
          depth[v] = depth[u] + 1;
          st.push_back(v);
        }
      }
    }
    vector<IdxDepth> a(tour.size());
    for(int i = 0; i < (int)tour.size(); i++) {
      int v = tour[i];
      a[i] = {v, depth[v]};
      pos[v] = i;
    }
    rmq = RmQ(move(a));
  }
  int operator()(int u, int v) {
    int pu = pos[u], pv = pos[v];
    if (pu > pv) swap(pu, pv);
    return rmq.query(pu, pv + 1).i;
  }
  int get_dist(int u, int v) {
    int c = (*this)(u, v);
    return depth[u] + depth[v] - 2 * depth[c];
  }
};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    x--, y--;
    VI a(k + 2);
    rep(i, k) cin >> a[i], a[i]--;
    a[k] = x, a[k+1] = y;
    VVI to(n);
    rep(_, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].emplace_back(v);
      to[v].emplace_back(u);
    }
    LCA lca(to);
    auto et = euler_tour_vertices(to);
    VI idx(n);
    rrep(i, 2 * n - 1) idx[et[i]] = i;
    sort(all(a), [&](int u, int v) {
      return idx[u] < idx[v];
    });
    ll ans = 0;
    rep(i, k + 2) ans += lca.get_dist(a[i], a[(i+1) % (k+2)]);
    ans -= lca.get_dist(x, y);
    cout << ans << '\n';
  }
}