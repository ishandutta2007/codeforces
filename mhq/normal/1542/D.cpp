#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
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
int n;
const int maxN = 505;
char tp[maxN];
int who[maxN];
int dp[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tp[i];
        if (tp[i] == '+') cin >> who[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (tp[i] == '+') {
            memset(dp, 0, sizeof dp);
            dp[0][0] = 1;
            for (int x = 1; x <= n; x++) {
                for (int cur = 0; cur <= x - 1; cur++) {
                    if (x == i) {
                        //only take
                        dp[x][cur] = sum(dp[x][cur], dp[x - 1][cur]);
                    }
                    else if (x < i) {
                        dp[x][cur] = sum(dp[x][cur], dp[x - 1][cur]);
                        if (tp[x] == '-') {
                            dp[x][max(cur - 1, 0)] = sum(dp[x][max(cur - 1, 0)], dp[x - 1][cur]);
                        }
                        else if (tp[x] == '+' && who[x] <= who[i]) {
                            dp[x][cur + 1] = sum(dp[x][cur + 1], dp[x - 1][cur]);
                        }
                        else {
                            dp[x][cur] = sum(dp[x][cur], dp[x - 1][cur]);
                        }
                    }
                    else {
                        dp[x][cur] = sum(dp[x][cur], dp[x - 1][cur]);
                        if (tp[x] == '-') {
                            if (cur > 0) {
                                dp[x][cur - 1] = sum(dp[x][cur - 1], dp[x - 1][cur]);
                            }
                        }
                        else if (tp[x] == '+' && who[x] < who[i]) {
                            dp[x][cur + 1] = sum(dp[x][cur + 1], dp[x - 1][cur]);
                        }
                        else {
                            dp[x][cur] = sum(dp[x][cur], dp[x - 1][cur]);
                        }
                    }
                }
            }
            int coef = 0;
            for (int cur = 0; cur <= n; cur++) {
                coef = sum(coef, dp[n][cur]);
            }
            ans = sum(ans, mult(coef, who[i]));
        }
    }
    cout << ans << '\n';
    return 0;
}