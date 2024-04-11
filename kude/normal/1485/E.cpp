#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
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
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VVI to(n);
        rep(i, n - 1) {
            int vi;
            cin >> vi;
            vi--;
            to[i+1].push_back(vi);
            to[vi].push_back(i+1);
        }
        VL a(n);
        rep(i, n - 1) cin >> a[i + 1];
        HLD d(to, 0);
        int dmax = 0;
        rep(i, n) chmax(dmax, d.depth[i]);
        dmax++;
        VVI dv(dmax);
        rep(i, n) dv[d.depth[i]].push_back(i);
        rep(i, dmax) sort(all(dv[i]), [&](int i, int j){return a[i] < a[j];});
        VL dp(n);
        rrep(z, dmax) {
            if (z == 0) continue;
            auto& vs = dv[z];
            int sz = vs.size();
            {
                rep(i, sz) {
                    int v = vs[i];
                    int p = d.parent[v];
                    chmax(dp[p], dp[v] + a[v] - a[vs.front()]);
                    chmax(dp[p], dp[v] + a[vs.back()] - a[v]);
                }
            }
            {
                ll now = -1001001001;
                rep(i, sz) {
                    int v = vs[i];
                    int p = d.parent[v];
                    if (i) chmax(dp[p], now + a[v]);
                    chmax(now, dp[v] - a[v]);
                }
            }
            {
                ll now = 0;
                rrep(i, sz) {
                    int v = vs[i];
                    int p = d.parent[v];
                    if (i + 1 < sz) chmax(dp[p], now - a[v]);
                    chmax(now, dp[v] + a[v]);
                }
            }
        }
        cout << dp[0] << '\n';
    }
}