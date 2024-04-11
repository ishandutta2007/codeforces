#include <bits/stdc++.h>
using namespace std;

const int M = 1005, N = 1005, DX[4] = {0, 1, 0, -1}, DY[4] = {-1, 0, 1, 0};

int m, n, ans = 0, row = 0, col = 0;
char s[M][N];

void DFS(int u, int v) {
    s[u][v] = '.';
    for (int i = 0; i < 4; i++) {
        if (s[u + DX[i]][v + DY[i]] == '#') {
            DFS(u + DX[i], v + DY[i]);
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
        int l = 0, r = -1;
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '#') {
                if (l == 0) {
                    l = j;
                }
                r = j;
            }
        }
        if (l > r) {
            row++;
        }
        for (int j = l; j <= r; j++) {
            if (s[i][j] == '.') {
                return cout << -1, 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = 0, r = -1;
        for (int j = 1; j <= m; j++) {
            if (s[j][i] == '#') {
                if (l == 0) {
                    l = j;
                }
                r = j;
            }
        }
        if (l > r) {
            col++;
        }
        for (int j = l; j <= r; j++) {
            if (s[j][i] == '.') {
                return cout << -1, 0;
            }
        }
    }
    if ((row == 0) ^ (col == 0)) {
        return cout << -1, 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '#') {
                ans++;
                DFS(i, j);
            }
        }
    }
    cout << ans;
}