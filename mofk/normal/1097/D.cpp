#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int mx = 1e7 * sqrt(10) + 10;
long long n;
int k;
bool pr[mx];
vector <int> prime;
int inv[101];

int pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * a * r % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}

vector <int> cal(int m) {
    vector <int> f(m + 1, 0);
    f[m] = 1;
    for (int i = 1; i <= k; ++i) {
        vector <int> g(m + 1, 0);
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= j; ++k)
                g[k] = (g[k] + 1LL * f[j] * inv[j + 1]) % mod;
        }
        f = g;
    }
    return f;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 100; ++i) inv[i] = pw(i, mod - 2);
    for (int i = 2; i < mx; ++i) if (!pr[i]) {
        prime.push_back(i);
        for (int j = i * 2; j < mx; j += i) pr[j] = 1;
    }
    long long cur = n;
    int ans = 1;
    for (int i = 0; 1LL * prime[i] * prime[i] <= n; ++i) if (cur % prime[i] == 0) {
        int cnt = 0;
        while (cur % prime[i] == 0) cur /= prime[i], ++cnt;
        vector <int> f = cal(cnt);
        int mul = 1, add = 0;
        for (int j = 0; j <= cnt; ++j) {
            add = (add + 1LL * mul * f[j]) % mod;
            mul = 1LL * mul * prime[i] % mod;
        }
        ans = 1LL * ans * add % mod;
    }
    if (cur > 1) {
        vector <int> f = cal(1);
        int mul = 1, add = 0;
        for (int j = 0; j <= 1; ++j) {
            add = (add + 1LL * mul * f[j]) % mod;
            mul = 1LL * mul * cur % mod;
        }
        ans = 1LL * ans * add % mod;
    }
    cout << ans << endl;
    return 0;
}