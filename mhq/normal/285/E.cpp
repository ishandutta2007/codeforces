#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int inv(int a) {
    return pw(a, mod - 2);
}
const int maxN = 1005;
int c[maxN][maxN];
int fact[maxN];
int n, k;
int dp[maxN][maxN][4];
int vals[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    c[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    }
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = mult(fact[i - 1], i);
    cin >> n >> k;
    // i -> (i - 1, i)
    dp[0][0][1] = true;
    for (int i = 0; i + 1 <= n; i++) {
        for (int k = 0; k <= i; k++) {
            for (int mask = 0; mask < 4; mask++) {
                dp[i + 1][k][mask / 2] = sum(dp[i + 1][k][mask / 2], dp[i][k][mask]);
                if (!(mask & 1)) {
                    dp[i + 1][k + 1][mask / 2] = sum(dp[i + 1][k + 1][mask / 2], dp[i][k][mask]);
                }
                if (i + 1 < n) {
                    dp[i + 1][k + 1][mask / 2 + 2] = sum(dp[i + 1][k + 1][mask / 2 + 2], dp[i][k][mask]);
                }
            }
        }
    }
    for (int p = 0; p <= n; p++) {
        for (int mask = 0; mask < 4; mask++) {
            vals[p] = sum(vals[p], dp[n][p][mask]);
        }
    }
    int ans = 0;
    for (int add = 0; add + k <= n; add++) {
        int coef = mult(fact[n - k - add], mult(vals[k + add], c[k + add][k]));
        if (add & 1) ans = sub(ans, coef);
        else ans = sum(ans, coef);
    }
    cout << ans;
    return 0;
}