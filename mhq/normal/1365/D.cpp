#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int m;
const int maxN = 55;
char c[maxN][maxN];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool used[maxN][maxN];
void dfs(int x, int y) {
    used[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (c[nx][ny] != '#' && !used[nx][ny]) {
            dfs(nx, ny);
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if (c[nx][ny] == '.') c[nx][ny] = '#';
                }
            }
        }
    }
    memset(used, 0, sizeof used);
    if (c[n][m] != '#') {
        dfs(n, m);
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'G') {
                if (!used[i][j]) ok = false;
            }
            if (c[i][j] == 'B') {
                if (used[i][j]) ok = false;
            }
        }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    cin >> n;
    return 0;
}