#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

void work() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, inf));
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        edges[i] = {u, v, b};
        dist[u][v] = min(dist[u][v], 1);
        dist[v][u] = min(dist[v][u], b ? -1 : 1);
    }
    for (int x = 1; x <= n; x++)
        dist[x][x] = min(dist[x][x], 0);
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == inf || dist[k][j] == inf)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if (dist[i][j] < -inf) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            cout << "NO\n";
            return;
        }
    }
    int st = -1, fn = -1, D = -inf;
    for (int s = 1; s <= n; s++) {
        for (int t = 1; t <= n; t++) {
            if (dist[s][t] > D) {
                D = dist[s][t];
                st = s, fn = t;
            }
        }
    }
    for (auto [u, v, b] : edges) {
        if (dist[st][u] == dist[st][v]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << dist[st][fn] << "\n";
    for (int i = 1; i <= n; i++) {
        cout << dist[st][i] << " ";
    }
    cout << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}