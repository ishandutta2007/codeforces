#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int mod = 998244353;
const int maxN = 2e5 + 10;
int w[maxN];
int a[maxN];
const int maxK = 3005;
int surv[maxK][maxK];
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
int r[maxN];
int dp[maxK][maxK];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int S0 = 0;
    int S1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        if (a[i] == 0) {
            S0 += w[i];
        }
        else {
            S1 += w[i];
        }
    }
    for (int i = m; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (i == m) {
                surv[i][j] = 1;
                dp[i][j] = 1;
            }
            else {
                if (S0 < (i - j)) continue;
                int dif = S0 + S1 + j - (i - j);
                int c = pw(dif, mod - 2);
                surv[i][j] = sum(surv[i][j], mult(surv[i + 1][j], mult(c, S0 - (i - j) - 1)));
                surv[i][j] = sum(surv[i][j], mult(surv[i + 1][j + 1], mult(c, S1 + j)));

                dp[i][j] = sum(dp[i][j], mult(dp[i + 1][j], mult(c, S0 - (i - j))));
                dp[i][j] = sum(dp[i][j], mult(dp[i + 1][j + 1], mult(c, S1 + j)));
                dp[i][j] = sum(dp[i][j], mult(dp[i + 1][j + 1], c));
                //S0 + j, S1 - (i - j)
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) r[i] = mult(w[i], surv[0][0]);
        else r[i] = mult(w[i], dp[0][0]);
        cout << r[i] << "\n";
    }
    return 0;
}