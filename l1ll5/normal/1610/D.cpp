#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200000 + 5;
const int mod = 1'000'000'007;
int Qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret = 1ll * ret * a % mod;
        }
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ret;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> buc(32);
    for (int i = 0; i < n; i += 1) {
        int x = a[i];
        int cnt = 0;
        while ((x & 1) == 0) {
            cnt++;
            x >>= 1;
        }
        buc[cnt]++;
    }
    LL ans = 0;
    vector<int> f(n + 1), inv(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i += 1) f[i] = 1ll * f[i - 1] * i % mod;
    for (int i = 0; i <= n; i += 1) inv[i] = Qpow(f[i], mod - 2);

    for (int i = 1; i <= 30; i += 1) {
        LL tmp = 0;
        for (int j = i + 1; j <= 30; j += 1) tmp += buc[j];
        LL C = Qpow(2, tmp);
        for (int j = 2; j <= buc[i]; j += 2) {
            LL D = C * f[buc[i]] % mod * inv[j] % mod * inv[buc[i] - j] % mod;
            ans = (ans + D) % mod;
        }
    }
    LL P = (Qpow(2, buc[0]) + mod - 1) % mod;
    P = P * Qpow(2, n - buc[0]) % mod;
    ans = (ans + P) % mod;
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--) {
        solve();
    }
}