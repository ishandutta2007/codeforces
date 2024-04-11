#include <bits/stdc++.h>

using namespace std;

const int N = 405, INF = 1e9;

int n, m, a, b;
int edge[N][N];
bool vis[N][N][2];
int dist[N][N][2];
priority_queue<pair<pair<int, int>, pair<int, int> > > Q;

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        edge[a][b] = edge[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    dist[1][1][0] = 0;
    Q.push({{0, 0}, {1, 1}});

    while (!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int state = Q.top().first.second;
        Q.pop();
        if (vis[x][y][state]) {
            continue;
        }
        vis[x][y][state] = true;
        if (state == 0) {
            if (x == n) {
                if (dist[x][y][1 - state] > dist[x][y][state] + 1) {
                    dist[x][y][1 - state] = dist[x][y][state] + 1;
                    Q.push({{-dist[x][y][1 - state], 1 - state}, {x, y}});
                }
            }
            for (int i = 1; i <= n; i++) {
                if (edge[x][i] && dist[i][y][1 - state] > dist[x][y][state] + 1) {
                    dist[i][y][1 - state] = dist[x][y][state] + 1;
                    Q.push({{-dist[i][y][1 - state], 1 - state}, {i, y}});
                }
            }
        } else {
            if (y == n) {
                if (dist[x][y][1 - state] > dist[x][y][state]) {
                    dist[x][y][1 - state] = dist[x][y][state];
                    Q.push({{-dist[x][y][1 - state], 1 - state}, {x, y}});
                }
            }
            for (int i = 1; i <= n; i++) {
                if (edge[y][i] == 0 && dist[x][i][1 - state] > dist[x][y][state]) {
                    dist[x][i][1 - state] = dist[x][y][state];
                    Q.push({{-dist[x][i][1 - state], 1 - state}, {x, i}});
                }
            }
        }
    }

    if (dist[n][n][0] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[n][n][0]);
    }

    return 0;
}