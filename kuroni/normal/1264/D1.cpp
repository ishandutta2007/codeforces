#include <bits/stdc++.h>
using namespace std;

const int N = 2005, MOD = 998244353;

int n, cnt[N], lef[N], rig[N];
char s[N];
long long ans = 0, coe[N], c[N][N], f[N][N];

long long C(int n, int k) {
    if (k > n || n < 0 || k < 0) {
        return 0;
    } else {
        return c[n][k];
    }
}

void init() {
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + (s[i] == '?');
        lef[i] = lef[i - 1] + (s[i] == '(');
        rig[i] = rig[i - 1] + (s[i] == ')');
    }
    c[0][0] = f[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = f[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            f[i][j] = (f[i][j - 1] + c[i][j]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1);
    n = strlen(s + 1);
    init();
    for (int i = 1; i < n; i++) {
        // middle position
        for (int j = 1; j <= i && j <= n - i; j++) {
            // number of left and right
            if (s[i] == ')' || lef[i - 1] >= j) {
                continue;
            }
            int le = cnt[i - 1], ri = cnt[n] - cnt[i];
            // ri position, at least j - rig[n] + rig[i]
            int mi = max(0, j - rig[n] + rig[i]), mx = ri;
            long long ch = 0;
            if (mi <= mx) {
                if (mi == 0) {
                    ch = f[ri][mx];
                } else {
                    ch = (f[ri][mx] - f[ri][mi - 1]) % MOD;
                }
            }
            // cout << i << " " << j << ": " << C(le, j - 1 - lef[i - 1]) * ch % MOD << '\n';
            (coe[j] += C(le, j - 1 - lef[i - 1]) * ch) %= MOD;
        }
    }
    for (int i = n; i >= 1; i--) {
        (ans += i * (coe[i] - coe[i + 1])) %= MOD;
    }
    cout << (ans + MOD) % MOD;
}