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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 205;
int l[maxN], r[maxN];
int c[maxN][maxN];
int n;
int dp[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > cord;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        cord.emplace_back(l[i]);
        cord.emplace_back(r[i] + 1);
    }
    reverse(l + 1, l + n + 1);
    reverse(r + 1, r + n + 1);
    sort(cord.begin(), cord.end());
    cord.erase(unique(cord.begin(), cord.end()), cord.end());
    for (int i = 0; i + 1 < cord.size(); i++) {
        int from = cord[i];
        int to = cord[i + 1] - 1;
        c[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            // (to - from) * .. * (to - from - j + 1) / (j * .. * 1)
            // (to - from + j - 1) / (1 * 2 * .. * j)
            // x_1 + .. + x_(to - from + 1) = j
            // C(to - from + j, j)
            c[i][j] = mult(c[i][j - 1], mult(to - from + j, pw(j, mod - 2)));
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i + 1 < cord.size(); i++) {
        int from = cord[i];
        int to = cord[i + 1] - 1;
        for (int j = 0; j <= n; j++) {
            for (int take = 0; take + j <= n; take++) {
                bool ok = true;
                for (int p = j + 1; p <= take + j; p++) {
                    if (r[p] < from || l[p] > to) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i + 1][j + take] = sum(dp[i + 1][j + take], mult(dp[i][j], c[i][take]));
                }
            }
        }
    }
    int coef = 1;
    for (int i = 1; i <= n; i++) coef = mult(coef, r[i] - l[i] + 1);
    cout << mult(dp[cord.size() - 1][n], pw(coef, mod - 2));
    return 0;
}