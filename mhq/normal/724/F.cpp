#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, d, mod;
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
const int maxN = 1005;
const int maxD = 12;
int c[maxN][maxD];
int val[maxN];
int invfact[maxN];
int ways[maxN];
void init() {
    for (int i = 0; i <= n; i++) {
        val[i] = (d - 1) * i + 1;
    }
    for (int i = 0; i <= d; i++) {
        invfact[i] = 1;
        if (i > 0) {
            invfact[i] = mult(invfact[i - 1], pw(i, mod - 2));
        }
    }
}
void calcC(int k) {
    int mlt = 1;
    c[k][0] = 1;
    for (int i = 1; i <= d; i++) {
        mlt = mult(mlt, ways[k] + i - 1);
        c[k][i] = mult(mlt, invfact[i]);
    }
}
int dp[maxN][maxN][maxD];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> d >> mod;
    if (n <= 2) {
        cout << 1;
        return 0;
    }
    if ((n - 2) % (d - 1) != 0) {
        cout << 0;
        return 0;
    }
    int need = (n - 2) / (d - 1);
    init();
    ways[0] = 1;
    for (int i = 0; i <= d; i++) {
        dp[0][0][i] = 1;
    }
    for (int i = 1; i < need; i++) {
        ways[i] = dp[i - 1][i - 1][d - 1];
        calcC(i);
        for (int have = 0; have < need; have++) {
            for (int cnt = 0; cnt <= d; cnt++) {
                for (int take = 0; take <= cnt && take * i <= have; take++) {
                    dp[i][have][cnt] = sum(dp[i][have][cnt], mult(dp[i - 1][have - take * i][cnt - take], c[i][take]));
                }
            }
        }
    }
    int at_most = 0;
    for (at_most = 0; ; at_most++) {
        if (1 + at_most * (d - 1) > n / 2) {
            at_most--;
            break;
        }
    }
    int ans = dp[at_most][need - 1][d];
    if (n % 2 == 0) {
        for (int p = 0; ; p++) {
            if (1 + p * (d - 1) == n / 2) {
                int all = ways[p];
                ans = sub(ans, mult((mod + 1) / 2, mult(all, sub(all, 1))));
            }
            if (1 + p * (d - 1) > n / 2) break;
        }
    }
    cout << ans;
    return 0;
}