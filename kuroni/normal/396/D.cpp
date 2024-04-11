#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5, MOD = 1E9 + 7, INV = (MOD + 1) / 2;

int n, a[N];
long long ans = 0, cur = 0, fct[N], ind[N];

struct SBIT {
    int bit[N];

    void update(int u, int v) {
        for (; u <= n; u += u & -u) {
            bit[u] += v;
        }
    }

    int query(int u) {
        int ret = 0;
        for (; u > 0; u -= u & -u) {
            ret += bit[u];
        }
        return ret;
    }
} bit;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    fct[0] = 1;
    for (int i = 1; i <= n; i++) {
        fct[i] = fct[i - 1] * i % MOD;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        int pos = bit.query(a[i]);
        ind[i] = (pos * fct[n - i] + ind[i + 1]) % MOD;
        (ans += bit.query(a[i])) %= MOD;
        bit.update(a[i], 1);
    }
    for (int i = 1; i <= n; i++) {
        int pos = bit.query(a[i]);
        (ans += 1LL * (pos - 1) * (pos - 2) / 2 % MOD * fct[n - i]) %= MOD;
        (ans += 1LL * (pos - 1) * fct[n - i] % MOD * (n - i) % MOD * (n - i - 1) % MOD * INV % MOD * INV) %= MOD;
        (ans += 1LL * (pos - 1) * ind[i + 1]) %= MOD;
        bit.update(a[i], -1);
    }
    cout << (ans + MOD) % MOD;
}