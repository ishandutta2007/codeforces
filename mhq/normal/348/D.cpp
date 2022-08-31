#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
int add(int a, int b) {
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}
int m, n;
char a[3005][3005];
int d1[3005][3005];
int d2[3005][3005];
int main() {
    //freopen("input.txt", "r", stdin);
    //cout << mult(100000, 100000);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    d1[n][m - 1] = 1;
    d2[n - 1][m] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (a[i][j] == '#') {
                d1[i][j] = 0;
                d2[i][j] = 0;
                continue;
            }
            d1[i][j] = add(add(d1[i + 1][j], d1[i][j + 1]), d1[i][j]);
            d2[i][j] = add(add(d2[i + 1][j], d2[i][j + 1]), d2[i][j]);
        }
    }
    //cout << d1[4][3] << " ";
    //cout << a[4][3];
    cout << (((1LL * d1[2][1] * d2[1][2]) - (1LL * d2[2][1] * d1[1][2]) % MOD) + MOD) % MOD;
    return 0;
}