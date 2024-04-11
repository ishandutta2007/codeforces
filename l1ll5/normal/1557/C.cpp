#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 5;
constexpr int mod = 1000000000 + 7;
int bin[maxn];
LL Qpow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    bin[0] = 1;

    for (int i = 1; i <= maxn - 4; i += 1)
        bin[i] = (bin[i - 1] << 1) % mod;
    while (T--) {
        int n, k;
        cin >> n >> k;
        LL ans = 0;
        LL cur = 1;
        if (n & 1) {
            for (int i = k - 1; i >= 0; i -= 1) {
                // all 1

                cur = cur * (bin[n - 1] + 1 + mod) % mod;
                // 
                // C(n, 0), C(n, 2) ... C(n, n - 2)
                // C40 C42 
                // 1 4 6 4 1 = 16 -> 2 ^ n
                // 1 5 10 10 5 1 -> 32
            }
            ans = cur;
            cout << ans << '\n';
            continue;
        }
        for (int i = k - 1; i >= 0; i -= 1) {
            // all 1
            ans += cur * Qpow(bin[i], n) % mod;
            ans %= mod;

            cur = cur * (bin[n - 1] - 1 + mod) % mod;
            // 
            // C(n, 0), C(n, 2) ... C(n, n - 2)
            // C40 C42 
            // 1 4 6 4 1 = 16 -> 2 ^ n
        }
        ans += cur;
        ans %= mod;
        cout << ans << '\n';
    }
}