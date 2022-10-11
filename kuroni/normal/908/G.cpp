#include <bits/stdc++.h>
using namespace std;

const int N = 705, D = 10, MOD = 1E9 + 7;

int n, sum[D];
char s[N];
long long ans = 0, f[N], c[N][N], pw[D][N];

void init() {
    f[0] = 0; c[0][0] = 1;
    for (int i = 0; i < D; i++) {
        pw[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        f[i] = (f[i - 1] * 10 + 1) % MOD;
        for (int j = 0; j < D; j++) {
            pw[j][i] = pw[j][i - 1] * j % MOD;
        }
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1); n = strlen(s + 1);
    init();
    for (int i = 1; i <= n; i++) {
        int di = s[i] - '0';
        for (int j = 1; j < D; j++) {
            for (int k = 0; k <= n - i; k++) {
                long long cur = c[n - i][k] * pw[D - j][k] % MOD * pw[j][n - i - k] % MOD;
                int cnt = k + sum[j];
                (ans += (f[cnt + 1] * max(0, di - j) + f[cnt] * min(j, di)) % MOD * cur) %= MOD;
            }
        }
        for (int j = 0; j <= di; j++) {
            sum[j]++;
        }
    }
    for (int i = 1; i < D; i++) {
        (ans += f[sum[i]]) %= MOD;
    }
    cout << ans;
}