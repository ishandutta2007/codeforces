#include <bits/stdc++.h>

using namespace std;

const int N = 1005, K = 4, INF = 1e6;
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

int n, m;
bool vis[N][N];
int dist[K][N][N];
char board[N][N];
priority_queue<pair<int, pair<int, int> > > Q;

void BFS(int col) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = false;
            if (col + 48 == board[i][j]) {
                dist[col][i][j] = 0;
                Q.push({0, {i, j}});
            } else {
                dist[col][i][j] = INF;
            }
        }
    }

    while (!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        Q.pop();
        if (vis[x][y]) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && vis[xx][yy] == false && board[xx][yy] != '#' && dist[col][x][y] + (board[xx][yy] == '.') < dist[col][xx][yy]) {
                dist[col][xx][yy] = dist[col][x][y] + (board[xx][yy] == '.');
                Q.push({-dist[col][xx][yy], {xx, yy}});
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }

    for (int i = 1; i <= 3; i++) {
        BFS(i);
    }

    int ans = 3 * INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int sum = 0;
//             cerr << "pole: " << i << " " << j << endl;
            for (int k = 1; k <= 3; k++) {
//                 cerr << dist[k][i][j] << endl;
                sum += dist[k][i][j];
            }
            ans = min(ans, sum - 2 * (board[i][j] == '.'));
        }
    }

    if (ans >= INF) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}