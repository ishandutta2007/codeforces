#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int modpow(int64_t e, int p) {
    int64_t r = 1;
    while (p) {
        if (p & 1) r = r * e % mod;
        e = e * e % mod;
        p >>= 1;
    }
    return r;
}

int solve(int N, int M, int C) {
    const int R = max({ N, M, C });
    vector<int64_t> fac(R + 1), ifac(R + 1), inv(R + 1);
    inv[1] = 1;
    fac[0] = ifac[0] = 1;
    for (int i = 2; i <= R; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    for (int i = 1; i <= R; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = ifac[i - 1] * inv[i] % mod;
    }

    int64_t ans = 0;
    for (int k = 0; k <= N && k <= C; k++) {
        ans = (ans + fac[N] * ifac[k] % mod * ifac[N-k] % mod 
                * fac[C] % mod * ifac[C - k] % mod * modpow(C - k, M) % mod
                * modpow(1LL * (C - k) * (C - k - 1) % mod, N - k)) % mod;
    }
    // cerr << N << ' ' << M << endl;
    return ans;
}

signed main() {
    int n, C;
    cin >> n >> C;

    vector<int64_t> D(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> D[i];

    for (int i = 1; i <= n; i++)
        D[i] += D[i - 1];

    if (D[n] % 2 == 1) {
        cout << solve(0, n, C) << '\n';
        return 0;
    }

    int N = 0, M = 0;
    const int64_t half = D[n] / 2;
    D.pop_back();
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (binary_search(D.begin(), D.end(), D[i] + half)) {
            int j = lower_bound(D.begin(), D.end(), D[i] + half) - D.begin();
            vis[j] = true;
            ++N;
        } else {
            ++M;
        }
    }

    cout << solve(N, M, C) << '\n';
}