
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct dsu {
    vector<int> a;
    dsu(int n) {
        a.assign(n, -1);
    }
    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

// read all queries to create an initial tree
// process new edge, check:
// - its cycle XOR is 1, so we query a path XOR to the root
// - it doesn't interfere with previous cycles.
// when we create a cycle, mark all nodes (excpet the highest one).
// when we see a new cycle, make sure all the nodes in question are currently unmarked

// operations:
// - mark a node: increment subtree by 1
// - check if path is unmarked: check that val(top) and val(bottom) are equal

const int N = 3e5 + 5;

int tree[4 * N];

int query(int i, int l, int r, int k) {
    if(l == r) return tree[i];
    int m = (l + r) / 2;
    if(k <= m) return tree[i] + query(2 * i + 1, l, m, k);
    else return tree[i] + query(2 * i + 2, m + 1, r, k);
}

void upd(int i, int l, int r, int L, int R, int x) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        tree[i] += x;
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    dsu D(n + 1);
    vector<array<int, 4>> ed;
    vector<vector<pii>> g(n + 1);
    vector<bool> ans(q, false);
    rep(i, 0, q) {
        int u, v, x;
        cin >> u >> v >> x;
        if(D.find(u) == D.find(v)) {
            ed.push_back({i, u, v, x});
        }else {
            D.join(u, v);
            ans[i] = true;
            g[u].push_back({v, x});
            g[v].push_back({u, x});
        }
    }
    vi xo(n + 1), tin(n + 1), tout(n + 1);
    vector<bool> vis(n + 1);
    vector<vi> par(n + 1, vi(20, 0));
    int ti = 0;
    auto dfs = [&](auto dfs, int x) -> void {
        vis[x] = true;
        tin[x] = ti++;
        for(auto &e : g[x]) {
            int y = e.first;
            if(!vis[y]) {
                par[y][0] = x;
                xo[y] = xo[x] ^ e.second;
                dfs(dfs, y);
            }
        }
        tout[x] = ti;
    };
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            par[i][0] = i;
            dfs(dfs, i);
        }
    }
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }
    auto anc = [&](int x, int y) {
        return tin[x] <= tin[y] && tout[y] <= tout[x];
    };
    auto lca = [&](int x, int y) {
        if(anc(x, y)) return x;
        for(int l = 19; l >= 0; l--) {
            if(!anc(par[x][l], y)) x = par[x][l];
        }
        return par[x][0];
    };
    for(auto &e : ed) {
        int i = e[0], u = e[1], v = e[2], x = e[3];
        int c = lca(u, v);
        if(xo[u] ^ xo[v] ^ x) {
            int mc = query(0, 0, n - 1, tin[c]);
            int mu = query(0, 0, n - 1, tin[u]);
            int mv = query(0, 0, n - 1, tin[v]);
            // use edge
            if(mc == mu && mc == mv) {
                while(u != c) {
                    upd(0, 0, n - 1, tin[u], tout[u] - 1, 1);
                    u = par[u][0];
                }
                while(v != c) {
                    upd(0, 0, n - 1, tin[v], tout[v] - 1, 1);
                    v = par[v][0];
                }
                ans[i] = true;
            }
        }
    }
    rep(i, 0, q) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}