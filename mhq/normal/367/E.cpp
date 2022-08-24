#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = sqrt(int(1e5) + 100) + 2;
int dp[maxN][maxN];
int ndp[maxN][maxN];
int n, m, x;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> x;
    if (n > m) {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i + 1 <= m; i++) {
        for (int all = 0; all <= min(i, n); all++) {
            for (int opened = 0; opened <= all; opened++) {
                ndp[all][opened] = 0;
            }
        }
        for (int all = 0; all <= min(i, n); all++) {
            for (int opened = 0; opened <= all; opened++) {
                if (dp[all][opened] == 0) continue;
                ndp[all + 1][opened + 1] = sum(ndp[all + 1][opened + 1], dp[all][opened]); // otkryli
                ndp[all + 1][opened] = sum(ndp[all + 1][opened], dp[all][opened]); // otkryli, zakryli
                if ((i + 1) != x) {
                    if (opened >= 1) ndp[all][opened - 1] = sum(ndp[all][opened - 1], dp[all][opened]); // zakryli
                    ndp[all][opened] = sum(ndp[all][opened], dp[all][opened]);
                }
            }
        }
        for (int all = 0; all <= min(i + 1, n); all++) {
            for (int opened = 0; opened <= all; opened++) {
                dp[all][opened] = ndp[all][opened];
            }
        }
    }
    int coef = 1;
    for (int i = 1; i <= n; i++) coef = mult(coef, i);
    cout << mult(coef, dp[n][0]);
    return 0;
}