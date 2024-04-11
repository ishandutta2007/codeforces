#include <bits/stdc++.h>
#define __lg(x) (x == 0 ? -1 : __lg(x))
using namespace std;

const int K = 5005, MOD = 998244353;

int n, p, k;
long long coe[K];

long long pw(int u, int p) {
    p = ((p % (MOD - 1)) + MOD - 1) % (MOD - 1);
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
    cin >> n >> p >> k; --p;
    coe[0] = 1;
    for (int i = 1; i < k; i++) {
        for (int j = i; j >= 0; j--) {
            (coe[j] *= (j + 1)) %= MOD;
            if (j > 0) {
                (coe[j] += coe[j - 1] * (n + j - i)) %= MOD;
            }
        }
    }
    long long ans = 0, cur = 1;
    for (int i = k - 1; i >= 0; i--) {
        (ans += coe[i] * cur) %= MOD;
        (cur *= p) %= MOD;
    }
    (ans *= 1LL * n % MOD * pw(p + 1, -k) % MOD) %= MOD;
    cout << (ans + MOD) % MOD;
}