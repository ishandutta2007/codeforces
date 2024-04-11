#include <bits/stdc++.h>
using namespace std;

const int N = 2005, MOD = 998244353;

int n;
long long a, b, w[N], l[N], tot[N], con[N], p[N], f[N][N];

long long pw(long long u, int p) {
    long long ret = 1;
    for (int i = __lg(p); i >= 0; i--) {
        (ret *= ret) %= MOD;
        if (p >> i & 1) {
            (ret *= u) %= MOD;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    b = pw(b, MOD - 2); (a *= b) %= MOD;
    w[0] = l[0] = 1;
    for (int i = 1; i <= n; i++) {
        w[i] = w[i - 1] * a % MOD;
        l[i] = l[i - 1] * (1 - a) % MOD;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        long long mov = 1LL * i * (i - 1) / 2;
        for (int j = 0; j <= i; j++) {
            f[i][j] = f[i - 1][j] * w[j] % MOD;
            if (j > 0) {
                (f[i][j] += f[i - 1][j - 1] * l[i - j]) %= MOD;
            }
            if (j > 0 && j < i) {
                long long tmp = f[i][j] * (1 - p[i - j]) % MOD;
                (con[i] += tmp * (tot[j] * (1 - p[j]) % MOD + con[j] * p[j] % MOD + tot[i - j])) %= MOD;
                (p[i] += tmp) %= MOD;
            }
        }
        long long inv = pw(p[i], MOD - 2);
        tot[i] = (mov + con[i]) * inv % MOD;
        (con[i] *= inv) %= MOD;
    }
    cout << (tot[n] + MOD) % MOD;
}