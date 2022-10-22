#include <bits/stdc++.h>
using namespace std;

const int maxn = 5025;
const int mod = 998244353;

int modmul(int64_t a, int64_t b) {
    return static_cast<int>(a * b % mod);
}
int modadd(int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

int64_t inv[maxn], fac[maxn], ifac[maxn];
int C(int n, int k) {
    if (k < 0 || n < k)
        return 0;
    return modmul(fac[n], modmul(ifac[k], ifac[n-k]));
}
int64_t dp[maxn][maxn];
int gao(vector<int> &cnt, int n) {
    vector<int> suf = cnt;
    for (int i = n - 1; i >= 0; i--)
        suf[i] += suf[i + 1];

    const auto calcHole = [&](int i, int j) {
        int h;
        if (j == n / 2) {
            h = n / 2;
        } else {
            h = j - 1;
        }
        h -= suf[i] - j;
        return h;
    };
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            dp[i][j] = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i])
            mx = i;
    if (cnt[mx] > 1) {
        return 0;
    }
    dp[mx][1] = 1;
    for (int i = mx - 1; i >= 1; i--) {
        int k = cnt[i];
        if (k > 0) {
            for (int j = 1; j <= n / 2; j++) {
                int hole = calcHole(i + 1, j - 1);
                dp[i][j] = modadd(dp[i][j], modmul(dp[i + 1][j - 1], C(hole, k - 1)));
            }
        }
        for (int j = 0; j <= n / 2; j++) {
            int hole = calcHole(i + 1, j);
            dp[i][j] = modadd(dp[i][j], modmul(dp[i + 1][j], C(hole, k)));
        }
        // for (int j = 0; j <= n / 2; j++)
        //     cerr << dp[i][j] << ' ';
        // cerr << endl;
    }
    return dp[1][n / 2];
}
int main() {
    inv[1] = 1;
    for (int i = 2; i < maxn; i++)
        inv[i] = modmul(inv[mod % i], mod - mod / i);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < maxn; i++)
        fac[i] = modmul(fac[i-1], i), ifac[i] = modmul(ifac[i-1], inv[i]);
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x] += 1;
        }
        cout << gao(cnt, n) << '\n';
    }
}