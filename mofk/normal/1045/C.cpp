#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, m;
vector<int> adj[N];
int hE[N];
int v[N][2];

int pa[N][20];
int pa2[N][20];
int lv[N], d[N];
int low[N], num[N];

int LCA(int u, int v) {
    if (lv[u] < lv[v]) swap(u, v);
    for(int i = 0, diff = lv[u] - lv[v]; diff; i++, diff >>= 1)
        if (diff & 1) u = pa[u][i];
    if (u == v) return u;
    for(int i = 19; i >= 0; i--) 
        if (pa[u][i] != pa[v][i]) 
            u = pa[u][i], v = pa[v][i];
    return pa[u][0];
}
queue<int> q;

void DFS(int x) {
    static int n1 = 0;
    low[x] = num[x] = ++n1;
    q.push(x);

    for(auto i : adj[x]) if (!hE[i]) {
        hE[i] = 1;
        int y = v[i][0] + v[i][1] - x; 
        if (!num[y]) {
            pa[y][0] = x;
            lv[y] = lv[x] + 1;
            DFS(y);
            low[x] = min(low[x], low[y]);
        } else low[x] = min(low[x], num[y]);
    }
}

int cal(int x, int z) {
    if (x == z) return 0;
    int rx = num[x], rz = num[z];
    int ans = 0;
    for(int i = 19; i >= 0; i--) {
        if (pa2[rx][i] > rz) {
            rx = pa2[rx][i];
            ans += 1 << i;
        }
    }
    return ans + 1;
}
int solve(int x, int y) {
    int z = LCA(x, y);
    return cal(x, z) + cal(y, z);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> n >> m >> test;
    for(int i = 1; i <= m; i++) {
        cin >> v[i][0] >> v[i][1];
        adj[v[i][0]].push_back(i);
        adj[v[i][1]].push_back(i);
    }
    DFS(1);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        d[x] = d[pa[x][0]] + (num[x] == low[x]);
    }

    for(int j = 1; j < 20; j++) 
        for(int i = 1; i <= n; i++) 
            pa[i][j] = pa[pa[i][j - 1]][j - 1];

    for(int i = 1; i <= n; i++) {
        pa2[num[i]][0] = min(num[pa[i][0]], low[i]);
        //cout << num[i] << "->" << pa2[num[i]][0] << '\n';
    }
    for(int j = 1; j < 20; j++) 
        for(int i = 1; i <= n; i++) 
            pa2[i][j] = pa2[pa2[i][j - 1]][j - 1];


    while (test--) {
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) << '\n';
    }
}