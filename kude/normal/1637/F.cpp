#include<bits/stdc++.h>
namespace {
using namespace std;
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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI h(n);
  rep(i, n) cin >> h[i];
  VVI to(n);
  rep(_, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    to[u].emplace_back(v);
    to[v].emplace_back(u);
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return h[i] > h[j];
  });
  int i_max = ord[0];
  HLD hld(to, i_max);
  VI cnt(n);
  vector<char> done(n);
  ll ans = 2 * h[i_max];
  cnt[i_max] = 2;
  done[i_max] = true;
  for(int idx = 1; idx < n; idx++) {
    int u = ord[idx];
    if (done[u]) continue;
    int v = u;
    while(true) {
      if (done[v]) break;
      done[v] = true;
      v = hld.parent[v];
    }
    cnt[u]++;
    if (cnt[v]) cnt[v]--;
    else ans += h[u];
  }
  cout << ans << '\n';
}