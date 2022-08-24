#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, mod;
const int maxN = 405;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
//int dp[maxN][maxN][maxN][3];
int dp[maxN][maxN];
int tot[maxN];
int c[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> mod;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int where = 1; where <= i; where++) {
            tot[i] = sum(tot[i], c[i - 1][where - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int take = 1; take <= i; take++) {
            if (take == i) {
                dp[i][take] = tot[i];
            }
            else {
                for (int last = 1; last + 2 <= i; last++) {
                    dp[i][take] = sum(dp[i][take], mult(dp[i - last - 1][take - last], mult(tot[last], c[take][last])));
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = sum(ans, dp[n][i]);
    cout << ans;
    /*dp[1][1][1][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int took = 0; took <= i; took++) {
            for (int last = 0; last <= i; last++) {
                for (int flag = 0; flag < 3; flag++) {
                    if (flag == 2) {
                        dp[i + 1][took + 1][1][0] = sum(dp[i + 1][took + 1][1][0], dp[i][took][last][flag]);
                    }
                    else if (flag == 1) {
                        dp[i + 1][took][0][2] = sum(dp[i + 1][took][0][2], dp[i][took][last][flag]);
                        dp[i + 1][took + 1][1][]
                    }
                    else {

                    }
                }
            }
        }
    }*/
    return 0;
}