#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e6 + 10;
int n, k;
int up[maxN][22];
vector < int > g[maxN];
bool ok[maxN];
int par[maxN];
int h[maxN];
vector < int > ans;
int need;
void dfs(int v, int p = -1) {
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) continue;
        par[to] = v;
        h[to] = h[v] + 1;
        up[to][0] = v;
        dfs(to, v);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int lg = 25;
    while ((1 << (lg - 1)) >= n) {
        lg--;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(n, -1);
    need = n - k - 1;
    ok[n] = true;
    par[n] = n;
    up[n][0] = n;
    for (int sz = 1; sz <= lg; sz++) {
        for (int v = 1; v <= n; v++) {
            up[v][sz] = up[up[v][sz - 1]][sz - 1];
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (ok[i]) continue;
        int cur = i;
        for (int sz = lg; sz >= 0; sz--) {
            if (!ok[up[cur][sz]]) cur = up[cur][sz];
        }
        cur = par[cur];
        int v = i;
        int color = h[i] - h[cur];
        if (color > need) {
            ans.push_back(i);
            continue;
        }
        else {
            need -= color;
            while (v != cur) {
                ok[v] = true;
                v = par[v];
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}