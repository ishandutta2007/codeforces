#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int M = 55, N = 55, DX[4] = {0, 1, 0, -1}, DY[4] = {1, 0, -1, 0};

int m, n, cnt = 0;
bool vis[M][N];
char s[M][N];

bool check() {
    queue<pair<int, int>> q;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            vis[i][j] = false;
            if (s[i][j] == '#' && q.empty()) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    int cur = q.size();
    for (; !q.empty(); q.pop()) {
        pair<int, int> u = q.front();
        for (int i = 0; i < 4; i++) {
            int x = u.fi + DX[i], y = u.se + DY[i];
            if (!vis[x][y] && s[x][y] == '#') {
                vis[x][y] = true;
                q.push({x, y});
                ++cur;
            }
        }
    }
    return cur < cnt - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '#') {
                cnt++;
            }
        }
    }
    if (cnt <= 2) {
        return cout << -1, 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '#') {
                s[i][j] = '.';
                if (check()) {
                    return cout << 1, 0;
                }
                s[i][j] = '#';
            }
        }
    }
    cout << 2;
}