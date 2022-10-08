
#include <bits/stdc++.h>

using namespace std;

const int N = 205, M = 2005;
int n, m, u[M], v[M], b[M];
int dist[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) dist[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> b[i];
        // build directed graph
        dist[u[i]][v[i]] = 1;
        dist[v[i]][u[i]] = (b[i] == 0 ? 1 : -1);
    }
    // Floyd-Warshall, detecting negative cycles if integer underflow
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if(dist[i][j] < -1e9) {
                        // integer underflow -> negative cycle
                        cout << "NO\n";
                        return 0;
                    }
                }
            }
        }
    }
    // (max dist, u)
    pair<int, int> best = {-1, 1};
    for(int i = 1; i <= n; i++) {
        if(dist[i][i] < 0) {
            // negative cycle
            cout << "NO\n";
            return 0;
        }
        for(int j = 1; j <= n; j++) {
            best = max(best, {dist[i][j], i});
        }
    }
    // check it is a valid answer. This handles bipartite check automatically.
    int s = best.second;
    for(int i = 0; i < m; i++) {
        if(dist[s][u[i]] == dist[s][v[i]]) {
            // non-bipartite
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n" << best.first << '\n';
    for(int i = 1; i <= n; i++) {
        cout << dist[s][i] << ' ';
    }
    cout << '\n';
}