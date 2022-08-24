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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 55;
int c[maxN][maxN];
int n, k;
int dp[maxN][maxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    if (n < 2 * k) {
        cout << 0;
        return 0;
    }
    c[0][0] = 1;
    for (int i = 1; i < maxN; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[1][0][1] = 1;
        if (i > 1) {
            for (int flag = 0; flag < 2; flag++) {
                for (int was = 0; was < maxN; was++) {
                    if (!dp[i - 1][was][flag]) continue;
                    dp[i][was + (flag + 1) / 2][flag ^ 1] = sum(dp[i][was + (flag + 1) / 2][flag ^ 1], mult(dp[i - 1][was][flag], i - 1));
                }
            }
            for (int cnt = 1; 2 * cnt <= i - 1; cnt++) {
                int ways = mult(mult(cnt, i - 1 - cnt), c[i - 1][cnt]);
                if (i - 1 == 2 * cnt) ways = mult(ways, (mod + 1) / 2);
                for (int flag1 = 0; flag1 < 2; flag1++) {
                    for (int was1 = 0; was1 < maxN; was1++) {
                        if (!dp[cnt][was1][flag1]) continue;
                        for (int flag2 = 0; flag2 < 2; flag2++) {
                            for (int was2 = 0; was2 < maxN; was2++) {
                                if (!dp[i - 1 - cnt][was2][flag2]) continue;
                                int nwas = was1 + was2 + (flag1 || flag2);
                                dp[i][nwas][!(flag1 || flag2)] = sum(dp[i][nwas][!(flag1 || flag2)], mult(dp[cnt][was1][flag1], mult(dp[i - 1 - cnt][was2][flag2], ways)));
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum(dp[n][k][0], dp[n][k][1]);
    return 0;
}