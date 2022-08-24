#include <bits/stdc++.h>
using namespace std;
const int maxN = 30;
int n, m;
int type[maxN][maxN];
int f[maxN][maxN];
int dp[maxN][maxN][maxN][maxN];
// x 0 .. 10, y 0 .. 10
// x + y 0 .. 20
// x - y -10 .. 10
// 1
int solve(int i1, int i2, int j1, int j2) {
    if (i1 > i2 || j1 > j2) return 0;
    if (dp[i1][i2][j1][j2] != -1) return dp[i1][i2][j1][j2];
    vector < int > v;
    for (int x = i1; x <= i2; x++) {
        for (int y = j1; y <= j2; y++) {
            if (f[x][y] == -1) continue;
            if (f[x][y] == 1) {
                v.push_back(solve(i1, x - 1, j1, j2) ^ solve(x + 1, i2, j1, j2));
            }
            else if (f[x][y] == 2) {
                v.push_back(solve(i1, i2, j1, y - 1) ^ solve(i1, i2, y + 1, j2));
            }
            else {
                v.push_back((solve(i1, x - 1, j1, y - 1) ^ solve(x + 1, i2, j1, y - 1)) ^
                            (solve(i1, x - 1, y + 1, j2) ^ solve(x + 1, i2, y + 1, j2)));
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int mx = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != i) {
            mx = i;
            break;
        }
    }
    if (mx == -1) mx = v.size();
    dp[i1][i2][j1][j2] = mx;
    return mx;
}
int get_grundy() {
    memset(dp, -1, sizeof dp);
    for (int i1 = 0; i1 <= (n + m + 4) / 2; i1++) {
        for (int i2 = i1; i2 <= (n + m + 4) / 2; i2++) {
            for (int j1 = 0; j1 <= (n + m + 4) / 2; j1++) {
                for (int j2 = 0; j2 <= (n + m + 4) / 2; j2++) {
                    solve(i1, i2, j1, j2);
                }
            }
        }
    }
    return dp[0][(n + m + 4) / 2][0][(n + m + 4) / 2];
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == 'L') type[i][j] = 1;
            else if (x == 'R') type[i][j] = 2;
            else type[i][j] = 3;
        }
    }
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (((i + j) & 1) == 1) {
                f[(i + j) / 2][(i - j + m) / 2] = type[i][j];
            }
        }
    }
    int x1 = get_grundy();
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (((i + j) & 1) == 0) f[(i + j) / 2][(i - j + m) / 2] = type[i][j];
        }
    }
    int x2 = get_grundy();
    if (x1 != x2) cout << "WIN";
    else cout << "LOSE";
    return 0;
}