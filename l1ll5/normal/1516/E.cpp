#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200 + 5;
const int mod = 1000000007;
int n, k, m;
int dp[N * 2][N * 2];
int Qpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = 1ll * ret * a % mod;
        b >>= 1;
        a = 1ll * a * a % mod;
    }
    return ret;
}
int inv[N * 2];
int Com[N * 2][N * 2];
int C(int n, int m) {
    int ret = 1;
    for (int i = n; i >= n - m + 1; i -= 1) {
        ret = 1ll * ret * i % mod;
    }
    for (int i = 1; i <= m; i += 1) {
        ret = 1ll * ret * inv[i] % mod;
    }
    return ret;
}
int ans[2] = {1, 0};
int main() {
    cin >> n >> k;
    m = min(n, 2 * k);
    for (int i = 1; i <= m; i += 1) inv[i] = Qpow(i, mod - 2);
    for (int i = 0; i <= m; i += 1) dp[i][0] = 1;
    Com[0][0] = 1;
    for (int i = 1; i <= m; i += 1) {
        Com[i][0] = 1;
        for (int j = 0; j <= m; j += 1) {
            dp[i][j] = (dp[i - 1][j] + 1ll * (i - 1) * dp[i - 1][j - 1]) % mod;
            Com[i][j] = (Com[i - 1][j - 1] + Com[i - 1][j]) % mod;
        }
    }
    for (int j = 1; j <= k; j += 1) {
        for (int i = 1; i <= m; i += 1) {
            int tmp = 0;
            for (int p = 0; p <= i; p += 1) {
                tmp = (tmp + ((p & 1) ? -1ll : 1ll) * Com[i][p] * dp[i - p][j] % mod) % mod;
                tmp += mod, tmp %= mod;
            }
            ans[j & 1] = (ans[j & 1] + 1ll * C(n, i) * tmp % mod) % mod;
        }
        printf("%d ", ans[j & 1]);
    }

}