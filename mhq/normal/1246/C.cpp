#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define free afajfajf
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int n, m;
const int maxN = 2002;
int dp[maxN][maxN][2];
int pref[maxN][maxN][2];
int free[maxN][maxN][2];
char c[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    if (c[n][m] == 'R') {
        cout << 0;
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            free[i][j][0] = free[i + 1][j][0];
            if (i + 1 <= n && c[i + 1][j] == '.') free[i][j][0]++;
            free[i][j][1] = free[i][j + 1][1];
            if (j + 1 <= m && c[i][j + 1] == '.') free[i][j][1]++;
        }
    }
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            // i ++
            if (i == n && j == m) {
                dp[i][j][0] = dp[i][j][1] = 1;
            }
            else {
                int moves = free[i][j][0];
                if (i + 1 <= n) {
                    dp[i][j][0] = sub(pref[i + 1][j][1], pref[i + 1 + moves][j][1]);
                }
                moves = free[i][j][1];
                if (j + 1 <= m) {
                    dp[i][j][1] = sub(pref[i][j + 1][0], pref[i][j + 1 + moves][0]);
                }
            }
            pref[i][j][1] = sum(pref[i + 1][j][1], dp[i][j][1]);
            pref[i][j][0] = sum(pref[i][j + 1][0], dp[i][j][0]);
        }
    }
    cout << sum(dp[1][1][0], dp[1][1][1]);
    return 0;
}