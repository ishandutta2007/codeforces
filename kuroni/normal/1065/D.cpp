#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 15, INF = 1E9 + 7, DX[8] = {1, 2, -1, -2, -1, -2, 1, 2}, DY[8] = {2, 1, -2, -1, 2, 1, -2, -1};

int n, u;
pair<int, int> dst[N][N][3];
pair<int, int> dp[N * N][3], pos[N * N];

bool valid(int u) {
    return u >= 1 && u <= n;
}

void BFS(int u) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dst[i][j][0] = dst[i][j][1] = dst[i][j][2] = {INF, INF};
        }
    }
    auto [sx, sy] = pos[u];
    priority_queue<tuple<pair<int, int>, int, int, int>, vector<tuple<pair<int, int>, int, int, int>>, greater<tuple<pair<int, int>, int, int, int>>> pq;
    for (int i = 0; i < 3; i++) {
        pq.push({dp[u][i], sx, sy, i});
    }
    while (!pq.empty()) {
        auto [cur, x, y, typ] = pq.top(); pq.pop();
        if (cur > dst[x][y][typ]) {
            continue;
        }
        pair<int, int> tmp = {cur.fi + 1, cur.se};
        if (typ == 0) {
            for (int i = 1; i <= n; i++) {
                if (tmp < dst[i][y][typ]) {
                    pq.push({dst[i][y][typ] = tmp, i, y, typ});
                }
                if (tmp < dst[x][i][typ]) {
                    pq.push({dst[x][i][typ] = tmp, x, i, typ});
                }
            }
        } else if (typ == 1) {
            for (int i = 1; i <= n; i++) {
                if (valid(x + y - i) && tmp < dst[i][x + y - i][typ]) {
                    pq.push({dst[i][x + y - i][typ] = tmp, i, x + y - i, typ});
                }
                if (valid(i + y - x) && tmp < dst[i][i + y - x][typ]) {
                    pq.push({dst[i][i + y - x][typ] = tmp, i, i + y - x, typ});
                }
            }
        } else {
            for (int i = 0; i < 8; i++) {
                int cx = x + DX[i], cy = y + DY[i];
                if (valid(cx) && valid(cy) && tmp < dst[cx][cy][typ]) {
                    pq.push({dst[cx][cy][typ] = tmp, cx, cy, typ});
                }
            }
        }
        tmp.se++;
        for (int i = 0; i < 3; i++) {
            if (i != typ && tmp < dst[x][y][i]) {
                pq.push({dst[x][y][i] = tmp, x, y, i});
            }
        }
    }
    auto [tx, ty] = pos[u + 1];
    for (int i = 0; i < 3; i++) {
        dp[u + 1][i] = dst[tx][ty][i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> u;
            pos[u] = {i, j};
        }
    }
    // 0 = rook, 1 = bishop, 2 = knight
    for (int i = 1; i < n * n; i++) {
        BFS(i);
    }
    auto [tx, ty] = pos[n * n];
    auto [l, r] = min(dst[tx][ty][0], min(dst[tx][ty][1], dst[tx][ty][2]));
    cout << l << " " << r << '\n';
}