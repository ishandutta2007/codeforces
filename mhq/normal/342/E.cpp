#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
const int LOG = 20;
int n, m;
vector < int > g[maxN];
int up[LOG][maxN];
vector < int > cur_block;
int dist[maxN], cur_dist[maxN];
int h[maxN];
void dfs(int v) {
    for (int to : g[v]) {
        if (dist[to] != -1) continue;
        dist[to] = dist[v] + 1;
        h[to] = h[v] + 1;
        up[0][to] = v;
        dfs(to);
    }
}
int find_dist(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int ans = h[u] + h[v];
    for (int i = LOG - 1; i >= 0; i--) {
        if (h[u] - (1 << i) >= h[v]) u = up[i][u];
    }
    if (u == v) return ans - 2 * h[u];
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    u = up[0][u];
    return ans - 2 * h[u];
}
void init() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(dist, -1, sizeof dist);
    dist[1] = 0;
    h[1] = 0;
    up[0][1] = -1;
    dfs(1);
    for (int i = 0; i + 1 < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            if (up[i][j] != -1) up[i + 1][j] = up[i][up[i][j]];
        }
    }
}
const int BLOCK = (int)(1.5 * sqrt((int)1e5));
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    init();
    int in_block = (m / BLOCK) + 1;
    for (int i = 1; i <= BLOCK + 1; i++) {
        for (int j = 1; j <= in_block; j++) {
            if (m == 0) break;
            int type, v;
            cin >> type >> v;
            m--;
            if (type == 1) {
                cur_block.push_back(v);
            }
            else {
                int ans = dist[v];
                for (int u : cur_block) ans = min(ans, find_dist(v, u));
                cout << ans << '\n';
            }
        }
        if (m == 0) break;
        if (cur_block.empty()) continue;
        memset(cur_dist, -1, sizeof cur_dist);
        queue < int > q;
        for (int u : cur_block) {
            cur_dist[u] = 0;
            q.push(u);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int to : g[u]) {
                if (cur_dist[to] != -1) continue;
                cur_dist[to] = cur_dist[u] + 1;
                q.push(to);
            }
        }
        for (int i = 1; i <= n; i++) dist[i] = min(cur_dist[i], dist[i]);
        cur_block.clear();
    }
    return 0;
}