#include <bits/stdc++.h>
using namespace std;

const int N = 2500, MOD = 998244353;

int m, n, c[2 * N][2 * N];
long long ans = 0, pre[2 * N];

void init() {
    for (int i = 0; i < 2 * N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

long long star_bars(int pos, int cnt) {
    return c[cnt + pos - 1][pos - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> m >> n;
    for (int i = 1; i < m; i++) {
        int le = i, ri = m - i;
        for (int j = 1; j <= n; j++) {
            long long cur = star_bars(j, ri) * star_bars(n + 1 - j, ri - 1) % MOD;
            pre[j] = (pre[j - 1] + cur) % MOD;
        }
        for (int j = 1; j < n; j++) {
            long long cur = star_bars(j, le) * star_bars(n + 1 - j, le - 1) % MOD;
            (ans += cur * pre[n - j - 1]) %= MOD;
        }
    }
    swap(m, n);
    for (int i = 1; i < m; i++) {
        int le = i, ri = m - i;
        for (int j = 1; j <= n; j++) {
            long long cur = star_bars(j, ri) * star_bars(n + 1 - j, ri - 1) % MOD;
            pre[j] = (pre[j - 1] + cur) % MOD;
        }
        for (int j = 1; j < n; j++) {
            long long cur = star_bars(j, le) * star_bars(n + 1 - j, le - 1) % MOD;
            (ans += cur * pre[n - j]) %= MOD;
        }
    }
    cout << ans * 2 % MOD;
}