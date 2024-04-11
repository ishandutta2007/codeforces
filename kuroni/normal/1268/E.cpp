#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 500005, M = 500005;

int n, m, cnt = 0, in[N], out[N], pa[N], f[N];
int val[M], ans[M], u[M], v[M];
bool vis[N], chk[M];
vector<int> le, ri, con, adj[N];

struct dsu {
    int dsu[N];

    void init() {
        fill(dsu + 1, dsu + n + 1, -1);
    }

    int trace(int u) {
        return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
    }

    bool connect(int u, int v) {
        if ((u = trace(u)) == (v = trace(v))) {
            return false;
        }
        if (dsu[u] > dsu[v]) {
            swap(u, v);
        }
        dsu[u] += dsu[v];
        dsu[v] = u;
        return true;
    }
} dsu;

void DFS(int u, int p = 0) {
    pa[u] = p;
    in[u] = ++cnt;
    f[u] = 1;
    for (int &v : adj[u]) {
        if (v != p) {
            DFS(u ^ val[v], v);
        }
    }
    out[u] = cnt;
}

void trace(int u, int v, vector<int> &ve) {
    ve.clear();
    while (!(in[u] <= in[v] && out[u] >= out[v])) {
        ve.push_back(pa[u]);
        u ^= val[pa[u]];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
        val[i] = u[i] ^ v[i];
    }
    dsu.init();
    for (int i = m; i >= 1; i--) {
        if (dsu.connect(u[i], v[i])) {
            chk[i] = true;
            adj[u[i]].push_back(i);
            adj[v[i]].push_back(i);
        }
    }
    DFS(1);
    for (int i = m; i >= 1; i--) {
        ans[i] = f[u[i]] + f[v[i]];
        if (!chk[i]) {
            trace(u[i], v[i], le); trace(v[i], u[i], ri);
            reverse(ri.begin(), ri.end());
            con.clear();
            for (int &v : le) {
                con.push_back(v);
            }
            for (int &v : ri) {
                con.push_back(v);
            }
            int pos = distance(con.begin(), max_element(con.begin(), con.end()));
            bool chk = true;
            for (int i = 1; i <= pos; i++) {
                if (con[i] < con[i - 1]) {
                    chk = false;
                }
            }
            for (int i = con.size() - 2; i >= pos; i--) {
                if (con[i] < con[i + 1]) {
                    chk = false;
                }
            }
            if (chk) {
                ans[i] -= ans[con[pos]];
            }
        }
        f[u[i]] = f[v[i]] = ans[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] - 1 << " ";
    }
}