#include <bits/stdc++.h>

using namespace std;

int n, mod;
int f[444][444];
int p2[444];
int c[444][444];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> mod;

    p2[0] = 1;
    for (int i = 1; i <= n; ++i) p2[i] = 2 * p2[i-1] % mod;
    c[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }

    f[0][0] = 1;
    f[1][0] = 1;
    f[2][0] = 2;
    f[3][0] = 4;
    f[3][1] = 2;
    for (int i = 4; i <= n; ++i) {
        f[i][0] = p2[i - 1];
        for (int j = 1; j <= i / 2; ++j) {
            for (int k = 2; k < i; ++k) {
                f[i][j] = (f[i][j] + 1ll * f[k - 1][j - 1] * p2[i - k - 1] % mod * c[i - j][i - k]) % mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) ans = (ans + f[n][i]) % mod;
    cout << ans << endl;
    return 0;
}