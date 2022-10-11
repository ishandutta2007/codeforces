#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 500005;

int n, u, v, h[N] = {-1}, g[N], pa[N], ans[N * 2], val[N];
int mx = 0, ed = 0, ch[N];
bool chk[N];
pair<int, int> f[N][2];
vector<int> adj[N], eve[N];

void DFS_1(int u, int p = 0) {
    h[u] = h[p] + 1;
    pa[u] = p;
    f[u][0] = {0, u}; f[u][1] = {-1, 0};
    for (int &v : adj[u]) {
        if (v != p) {
            DFS_1(v, u);
            pair<int, int> tmp = f[v][0];
            tmp.fi++; tmp.se = v;
            for (int i = 0; i < 2; i++) {
                if (tmp > f[u][i]) {
                    swap(tmp, f[u][i]);
                }
            }
        }
    }
}

void DFS_2(int u, int p = 0) {
    eve[0].push_back(u);
    if (p != 0) {
        g[u] = max(g[p], f[p][0].se == u ? f[p][1].fi : f[p][0].fi) + 1;
        eve[g[u]].push_back(u);
    }
    for (int &v : adj[u]) {
        if (v != p) {
            eve[f[v][0].fi + 1].push_back(u);
            DFS_2(v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS_1(1);
    DFS_2(1);
    for (int i = n; i >= 0; i--) {
        int ev = i * 2, od = i * 2 + 1;
        ans[od] = mx;
        for (int &v : eve[i]) {
            if (!chk[v]) {
                chk[v] = true;
                ans[od] = max(ans[od], val[v] + 1);
            }
        }
        for (int &v : eve[i]) {
            chk[v] = false;
            mx = max(mx, ++val[v]);
            ed = max(ed, val[v] + ch[v] - 2);
            if (v != 1) {
                ed = max(ed, val[pa[v]] + (ch[pa[v]] = max(ch[pa[v]], val[v])) - 2);
            }
        }
        ans[ev] = max(mx, ed);
    }
    for (int i = 1; i <= n; i++) {
        cout << max(ans[i], 1) << " ";
    }
}