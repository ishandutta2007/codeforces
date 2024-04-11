#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 55, M = 1E5 + 5, INF = 1E6 + 7;

int n, m, u, v, s, t, cnt = 0, deg[N], ind[N][N];
int w[M], tr[M], dst[M], pot[M], val[M];
bool ans[N][N];

struct edge {
    int v, c, ind;

    edge(int _v, int _c, int _ind) : v(_v), c(_c), ind(_ind) {}
};
vector<edge> adj[M];

void add_edge(int u, int v, int co) {
    adj[u].push_back(edge(v, co, cnt));
    val[cnt] = u ^ v; w[cnt++] = 1;
    adj[v].push_back(edge(u, -co, cnt));
    val[cnt] = u ^ v; w[cnt++] = 0;
}

void dijkstra() {
    fill(dst + 1, dst + t + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dst[s] = 0, 0});
    while (!pq.empty()) {
        pair<int, int> u = pq.top(); pq.pop();
        if (u.fi > dst[u.se]) {
            continue;
        }
        for (edge &v: adj[u.se]) {
            int nxt = u.fi + pot[u.se] + v.c - pot[v.v];
            if (dst[v.v] > nxt && w[v.ind] > 0) {
                tr[v.v] = v.ind;
                pq.push({dst[v.v] = nxt, v.v});
            }
        }
    }
}

void trace() {
    for (int u = t; u != s; u ^= val[tr[u]]) {
        w[tr[u]]--; w[tr[u] ^ 1]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        deg[u]++;
        ans[u][v] = true;
        ind[u][v] = ind[v][u] = -1;
    }
    s = 0; t = n + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (ind[i][j] == 0) {
                ind[i][j] = t++;
                add_edge(s, ind[i][j], 0);
                add_edge(ind[i][j], i, 0);
                add_edge(ind[i][j], j, 0);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = deg[i] + 1; j < n; j++) {
            add_edge(i, t, 2 * j - 1);
        }
    }
    for (int i = m + 1; i <= n * (n - 1) / 2; i++) {
        dijkstra();
        trace();
        for (int j = 0; j <= t; j++) {
            pot[j] += dst[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ind[i][j] > 0) {
                ans[i][j] = w[adj[ind[i][j]].back().ind];
                ans[j][i] = !ans[i][j];
            }
            cout << ans[i][j];
        }
        cout << '\n';
    }
}