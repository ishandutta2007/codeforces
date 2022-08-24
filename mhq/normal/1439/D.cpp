#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int mod;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 505;
int dp[maxN];
int sumWays[maxN];
int n, m;
int sumPref[maxN];
int ans[maxN][maxN];
int sumAns[maxN][maxN];
int c[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> mod;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        sumPref[i] = sum(sumPref[i - 1], i);
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int last = 1; last <= i; last++) {
            int cc = mult(i + 1, mult(mult(c[i - 1][last - 1], dp[last - 1]), dp[i - last]));
            dp[i] = sum(dp[i], cc);
            sumWays[i] = sum(sumWays[i], mult(sumWays[last - 1], mult(i + 1, mult(c[i - 1][last - 1], dp[i - last]))));
            sumWays[i] = sum(sumWays[i], mult(sumWays[i - last], mult(i + 1, mult(c[i - 1][last - 1], dp[last - 1]))));
            int dd = mult(c[i - 1][last - 1], mult(dp[last - 1], dp[i - last]));
            sumWays[i] = sum(sumWays[i], mult(sumPref[last - 1], dd));
            sumWays[i] = sum(sumWays[i], mult(sumPref[i - last], dd));
        }
    }

    ans[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int cnt = 0; cnt <= i; cnt++) {
            ans[i][cnt] = sum(ans[i][cnt], ans[i - 1][cnt]);
            sumAns[i][cnt] = sum(sumAns[i][cnt], sumAns[i - 1][cnt]);
            for (int last = 1; last <= cnt; last++) {
                if (last == cnt) {
                    ans[i][cnt] = sum(ans[i][cnt], dp[cnt]);
                    sumAns[i][cnt] = sum(sumAns[i][cnt], sumWays[cnt]);
                }
                else {
                    if (last + 1 <= i) {
                        ans[i][cnt] = sum(ans[i][cnt], mult(c[cnt][last], mult(ans[i - last - 1][cnt - last], dp[last])));
                        sumAns[i][cnt] = sum(sumAns[i][cnt], mult(c[cnt][last], mult(ans[i - last - 1][cnt - last], sumWays[last])));
                        sumAns[i][cnt] = sum(sumAns[i][cnt], mult(c[cnt][last], mult(sumAns[i - last - 1][cnt - last], dp[last])));
                    }
                }
            }
        }
    }
    cout << sumAns[n][m];
    return 0;
}