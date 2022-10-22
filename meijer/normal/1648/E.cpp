#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5+10;

int t, n, m;
int a[MX], b[MX], c[MX];
int sc[MX];
int ans[MX];
unordered_set<int> adj[MX];
int curc;

struct DSU2 {
    int p[MX], sz[MX], d[MX], nxt[MX], lst[MX];
    vector<int> chl[MX];
    int p2[MX][20], c2[MX][20];
    void build() {
        for (int i=1; i<=n; i++)
            p[i] = i, sz[i] = 1, p2[i][0] = i, c2[i][0] = 0, chl[i] = {}, d[i] = 0, lst[i] = i, nxt[i] = -1;
    }
    int g(int u) {return p[u] == u ? u : p[u] = g(p[u]);}
    void unite(int u, int v) {
        u = g(u), v = g(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u,v);
        sz[v] += sz[u];
        p[u] = v, chl[v].push_back(u);
        nxt[lst[v]] = u, lst[v] = lst[u];
        p2[u][0] = v, c2[u][0] = curc;
    }
    bool canCombine(int u, int v) {
        for (u=g(u); u!=-1; u=nxt[u])
            for (int w=g(v); w!=-1; w=nxt[w])
                if (!adj[u].count(w))
                    return 1;
        return 0;
    }
    void dfs(int u) {
        for (int v : chl[u]) {
            d[v] = d[u]+1;
            dfs(v);
        }
    }
    void fillAns() {
        dfs(g(1));
        for (int j=1; j<20; j++) {
            for (int i=1; i<=n; i++) {
                p2[i][j] = p2[p2[i][j-1]][j-1];
                c2[i][j] = max(c2[i][j-1],c2[p2[i][j-1]][j-1]);
            }
        }
        for (int x=0; x<m; x++) {
            int res = 0, u = a[x], v = b[x];
            if (d[u] < d[v]) swap(u,v);
            for (int i=19; i>=0; i--)
                if ((1<<i) & (d[u]-d[v]))
                    res = max(res, c2[u][i]), u = p2[u][i];
            for (int i=19; i>=0; i--) {
                if (p2[u][i] != p2[v][i]) {
                    res = max(res, max(c2[u][i], c2[v][i]));
                    u = p2[u][i], v = p2[v][i];
                }
            }
            if (u != v)
                res = max(res, max(c2[u][0], c2[v][0]));
            ans[x] = res;
        }
    }
} dsu2;

struct DSU1 {
    int p[MX], r[MX], sz[MX];
    vector<int> cc[MX];
    void build() {
        for (int i=1; i<=n; i++)
            p[i] = i, r[i] = 1, cc[i] = {i}, sz[i] = 1;
    }
    int g(int u) {return p[u] == u ? u : p[u] = g(p[u]);}
    void unite(int u, int v) {
        u = g(u), v = g(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u,v);
        vector<int> res = cc[v];
        for (int x : cc[u]) {
            vector<int> nres;
            for (int y : res) {
                if (dsu2.canCombine(x,y)) {
                    dsu2.unite(x,y);
                } else {
                    nres.push_back(y);
                }
            }
            nres.push_back(x);
            res = nres;
        }
        p[v] = u;
        sz[u] += sz[v];
        cc[u] = res;
    }
} dsu1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<m; i++)
            cin >> a[i] >> b[i] >> c[i];
        
        // create edges set
        for (int i=1; i<=n; i++)
            adj[i].clear();
        for (int i=0; i<m; i++)
            adj[a[i]].insert(b[i]), adj[b[i]].insert(a[i]);

        iota(sc,sc+m,0);
        sort(sc,sc+m,[](int i, int j) {
            return c[i] < c[j];
        });
        
        // find answer
        dsu1.build();
        dsu2.build();
        for (int i=0; i<m; i++) {
            curc = c[sc[i]];
            dsu1.unite(a[sc[i]], b[sc[i]]);
        }
        dsu2.fillAns();

        // print answer
        for (int i=0; i<m; i++)
            cout << (i == 0 ? "" : " ") << ans[i];
        cout << endl;
    }
}