#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
const int INF = 1e9 + 128;
int d[nax][nax]; /// shortest path from x -> y in general graph
vector <tuple <int, int, int>> edges;
int n, m, k;


int main() {
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= n ; ++ j)
            d[i][j] = INF;
        d[i][i] = 0;
    }
    for (int i = 1 ; i <= m ; ++ i) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
        edges.emplace_back(u, v, w);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector < pair <int, int> > routes(k);

    for (auto &[x, y] : routes) {
        cin >> x >> y;
    }

    int ans = INF;

    for (const auto &[u, v, w] : edges) {
        int sum = 0;

        for (const auto &[x, y] : routes) {
            sum += min({d[x][y], d[x][u] + d[v][y], d[x][v] + d[u][y]});
        }
        ans = min(ans, sum);
    }

    cout << ans << '\n';

}