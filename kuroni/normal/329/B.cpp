#include <bits/stdc++.h>
using namespace std;

const int M = 1005, N = 1005, MX = 15;
const int DX[4] = {0, 1, 0, -1}, DY[4] = {1, 0, -1, 0};

int m, n, dst[M][N];
bool chk[MX];
char s[M][N];

bool check(int x, int y) {
    if (x == 0 || x == m + 1 || y == 0 || y == n + 1) {
        return false;
    } else {
        return s[x][y] != 'T';
    }
}

void BFS(int x, int y) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dst[i][j] = M * N;
        }
    }
    queue<int> qx, qy;
    dst[x][y] = 0;
    for (qx.push(x), qy.push(y); !qx.empty(); qx.pop(), qy.pop()) {
        int u = qx.front(), v = qy.front();
        for (int i = 0; i < 4; i++) {
            int tx = u + DX[i], ty = v + DY[i];
            if (check(tx, ty) && dst[tx][ty] == M * N) {
                dst[tx][ty] = dst[u][v] + 1;
                qx.push(tx); qy.push(ty);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> (s[i] + 1);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 'E') {
                BFS(i, j);
            }
        }
    }
    int rep = 0, ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 'S') {
                rep = dst[i][j];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (isdigit(s[i][j])) {
                ans += (s[i][j] - '0') * (dst[i][j] <= rep);
            }
        }
    }
    cout << ans;
}