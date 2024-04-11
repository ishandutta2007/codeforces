#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n, k;
int f[5005];
int c[5005][5005];
int pw[5005];
int inv[5005];

int _pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * r * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    c[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
    for (int i = 1; i <= k; ++i) {
        pw[i] = 1;
        for (int j = 1; j <= k; ++j) pw[i] = 1ll * pw[i] * i % mod;
    }
    for (int i = 0; i <= k; ++i) {
        for (int j = 1; j <= i; ++j)
            f[i] = (f[i] + 1ll * pw[j] * c[i][j]) % mod;
        f[i] = 1ll * f[i] * _pw(2, mod - 1 - i) % mod;
    }
    for (int i = 0; i <= k; ++i) inv[i] = _pw(i, mod - 2);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        int add = 1;
        for (int j = 0; j <= k; ++j) if (j != i) {
            int sign = (i < j) ? (mod - 1) : 1, v = abs(i - j);
            add = 1ll * sign * add % mod * (n + mod - j) % mod * inv[v] % mod;
        }
        ans = (ans + 1ll * f[i] * add) % mod;
    }
    ans = 1ll * ans * _pw(2, n) % mod;
    cout << ans << endl;
    return 0;
}