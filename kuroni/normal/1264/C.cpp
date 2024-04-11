#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 2E5 + 5, MOD = 998244353, INV = 828542813;

int n, q, u;
long long ans, f[N], c[N], g[N], h[N], p[N];
set<int> se;

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

long long calculate(int l, int r) {
    long long tmp = f[r - 1] - f[l - 1];
    (tmp *= pw(g[l - 1], MOD - 2)) %= MOD;
    long long coe = c[r - 1] - c[l - 1];
    (coe *= pw(g[l - 1], MOD - 2)) %= MOD;
    long long mid = pw(g[r - 1], MOD - 2) * g[l - 1] % MOD;
    return ((tmp - coe * (l - 1)) % MOD * mid) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        (p[i] *= INV) %= MOD;
    }
    g[0] = h[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] + g[i - 1] * (1 - p[i]) % MOD * i) % MOD;
        c[i] = (c[i - 1] + g[i - 1] * (1 - p[i])) % MOD;
        g[i] = g[i - 1] * p[i] % MOD;
        h[i] = h[i - 1] * (1 - p[i]) % MOD;
    }
    ans = (calculate(1, n + 1) + n) % MOD; se.insert(1); se.insert(n + 1);
    while (q--) {
        cin >> u;
        if (se.find(u) != se.end()) {
            se.erase(u);
            auto it = se.upper_bound(u);
            int l = *prev(it), r = *it;
            ans -= calculate(l, u);
            ans -= calculate(u, r);
            ans += calculate(l, r);
            ans %= MOD;
        } else {
            auto it = se.upper_bound(u);
            int l = *prev(it), r = *it;
            ans += calculate(l, u);
            ans += calculate(u, r);
            ans -= calculate(l, r);
            ans %= MOD;
            se.insert(u);
        }
        cout << (ans + MOD) % MOD << '\n';
    }
}