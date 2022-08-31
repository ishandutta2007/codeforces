#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 205;
const int SHIFT = 205;
ld dp[maxN][maxN][2 * maxN];
int n, l, k;
int a[maxN];
ld p[maxN];
const ld eps = 1e-12;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> l >> k;
    dp[0][0][min(n, k) + SHIFT] = 1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[i] = (ld)(x) / 100;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i + 1 <= n; i++) {
        for (int wins = 0; wins <= i; wins++) {
            for (int bal = -n; bal <= n; bal++) {
                if (dp[i][wins][bal + SHIFT] < eps) continue;
                if (a[i] == -1) {
                    dp[i + 1][wins][bal + SHIFT] += dp[i][wins][bal + SHIFT] * (1 - p[i]);
                    dp[i + 1][wins + 1][bal - 1 + SHIFT] += dp[i][wins][bal + SHIFT] * p[i];
                }
                else {
                    dp[i + 1][wins][bal + SHIFT] += dp[i][wins][bal + SHIFT] * (1 - p[i]);
                    dp[i + 1][wins + 1][min(bal + a[i], n) + SHIFT] += dp[i][wins][bal + SHIFT] * p[i];
                }
            }
        }
    }
    ld ans = 0;
    for (int wins = l; wins <= n; wins++) {
        for (int bal = 0; bal <= n; bal++) {
            ans += dp[n][wins][bal + SHIFT];
        }
    }
    cout << fixed << setprecision(10) << ans;
    return 0;
}