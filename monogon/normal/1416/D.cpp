
#pragma GCC optimize ("Ofast")
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

// build tree of components merging
// add edges in reverse query order
// node (from 1 to n) or edge removal (n + idx + 1) if just after edge index idx

const int N = 6e5 + 5, M = 6e5 + 5, Q = 6e5 + 5;
int n, m, q;
int p[N], a[M], b[M];
int dsu[N], repr[N], tinv[N + M];
vi adj[N + M];
pii tree[4 * (N + M)];
bool used[M];

pii add(pii p1, pii p2) {
    if(p1.first >= p2.first) {
        return p1;
    }else {
        return p2;
    }
}
void build(int i, int l, int r) {
    if(l == r) {
        if(tinv[l] <= n) {
            tree[i] = {p[tinv[l]], l};
        }else {
            tree[i] = {0, l};
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = add(tree[2 * i + 1], tree[2 * i + 2]);
}

pii query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return {0, l};
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return add(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}

// reset position k to 0
void upd(int i, int l, int r, int k) {
    if(l == r) {
        tree[i] = {0, k};
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k);
    else upd(2 * i + 2, m + 1, r, k);
    tree[i] = add(tree[2 * i + 1], tree[2 * i + 2]);
}

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y, int r) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
    repr[x] = r;
}

bool vis[N + M];
int tin[N + M], tout[N + M], ti = 0;
int par[N + M][20];

void dfs(int x, int p) {
    par[x][0] = p;
    vis[x] = true;
    tin[x] = ti++;
    tinv[tin[x]] = x;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y, x);
        }
    }
    tout[x] = ti;
}

struct query {
    int ty, i;
} qu[Q];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    fill(dsu, dsu + N, -1);
    rep(i, 1, n + 1) {
        repr[i] = i;
    }
    rep(i, 1, n + 1) {
        cin >> p[i];
    }
    rep(i, 1, m + 1) {
        cin >> a[i] >> b[i];
    }
    rep(i, 0, q) {
        cin >> qu[i].ty >> qu[i].i;
    }
    vi edges;
    // cout << "Graph" << endl;
    auto applyedge = [&](int idx) {
        if(trace(a[idx]) != trace(b[idx])) {
            used[idx] = true;
            edges.push_back(idx);
            // par[a[idx]] = par[b[idx]] = ;
            int arep = repr[trace(a[idx])];
            int brep = repr[trace(b[idx])];
            // adj[arep].push_back(n + idx + 1);
            // adj[brep].push_back(n + idx + 1);
            adj[n + idx + 1].push_back(arep);
            adj[n + idx + 1].push_back(brep);
            // cout << "edge " << idx << " joining " << arep << " and " << brep << endl;
            join(a[idx], b[idx], n + idx + 1);
        }
    };
    vector<bool> bruh(m + 1, false);
    rep(i, 0, q) {
        if(qu[i].ty == 2) {
            bruh[qu[i].i] = true;
        }
    }
    rep(idx, 1, m + 1) {
        if(!bruh[idx]) {
            applyedge(idx);
        }
    }
    for(int i = q - 1; i >= 0; i--) {
        if(qu[i].ty == 2) {
            int idx = qu[i].i;
            // merge a[idx] and b[idx]
            if(!used[idx]) {
                applyedge(idx);
            }
        }
    }
    reverse(all(edges));
    for(int idx : edges) {
        if(!vis[n + idx + 1]) {
            dfs(n + idx + 1, n + idx + 1);
        }
    }
    
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            dfs(i, i);
        }
    }
    build(0, 0, ti);
    rep(l, 1, 20) {
        rep(i, 0, N + M) {
            par[i][l] = par[par[i][l - 1]][l - 1];
        }
    }
    rep(i, 0, q) {
        if(qu[i].ty == 1) {
            int v = qu[i].i;
            // use DSU parent info to find out the interval we should query
            // binary lifting on the tree?
            for(int l = 19; l >= 0; l--) {
                // par[v][l] used already?
                if(par[v][l] > n && used[par[v][l] - (n + 1)]) {
                    v = par[v][l];
                }
            }
            pii pa = query(0, 0, ti, tin[v], tout[v] - 1);
            int mx, pos;
            tie(mx, pos) = pa;
            cout << mx << '\n';
            if(mx > 0) {
                upd(0, 0, ti, pos);
            }
        }else {
            used[qu[i].i] = false;
        }
    }
}