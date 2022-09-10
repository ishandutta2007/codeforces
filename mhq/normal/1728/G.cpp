#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int d, n, m;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 3e5 + 10;
int inv[maxN];
int coef[21][21];
int prod_bad[21][21];
int l[maxN], f[21];
int cur_dp[21];
void add(int a, int tp) {
    int to_mult = (tp == 1 ? (d + 1) : inv[d + 1]);
    for (int i = 0; i < (m + 1); i++) {
        for (int j = i + 1; j <= m + 1; j++) {
            if (f[i] < a && a < f[j]) {
                coef[i][j] = mult(coef[i][j], to_mult);
                if (i == 0 && j == m + 1) continue;
                int delta = min(a - f[i], f[j] - a);
                if (tp == 1) {
                    prod_bad[i][j] = mult(prod_bad[i][j], delta);
                }
                else {
                    prod_bad[i][j] = mult(prod_bad[i][j], inv[delta]);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> d >> n >> m;
    inv[1] = 1;
    for (int i = 2; i <= d + 1; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> f[i];
    }
    sort(f + 1, f + m + 1);
    f[0] = -2 * d - 228;
    f[m + 1] = 2 * d + 228;
    for (int i = 0; i < (m + 1); i++) {
        for (int j = i + 1; j <= m + 1; j++) {
            prod_bad[i][j] = 1;
            coef[i][j] = 1;
        }
    }
    prod_bad[0][m + 1] = 0;
    for (int i = 1; i <= n; i++) {
        add(l[i], +1);
    }
    int q;
    cin >> q;
    while (q--) {
        int r;
        cin >> r;
        add(r, +1);
        cur_dp[0] = 1;
        for (int i = 1; i <= m + 1; i++) {
            cur_dp[i] = 0;
            for (int j = 0; j < i; j++) {
                cur_dp[i] = sub(cur_dp[i], mult(cur_dp[j], prod_bad[j][i]));
            }
        }
        cout << sub(coef[0][m + 1], cur_dp[m + 1]) << '\n';
        add(r, -1);

    }


    return 0;
}