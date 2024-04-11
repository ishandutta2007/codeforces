#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 5005;
int fact[2 * maxN];
int invfact[2 * maxN];
int inv[2 * maxN];
int n, k;
int dp[maxN][maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = inv[1] = fact[1] = invfact[1] = 1;
    for (int i = 2; i < 2 * maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> n >> k;
    dp[0][0] = 1;
    // k ^(cnt)
    // E[x1 * x2 .. xk]
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int cnt = 0; cnt <= i - 1; cnt++) {
            dp[i][cnt] = sum(dp[i][cnt], dp[i - 1][cnt]);
            dp[i][cnt + 1] = sum(dp[i][cnt + 1], mult(dp[i - 1][cnt], a[i]));
        }
    }
    int ans = 0;
    for (int cnt = 1; cnt <= n; cnt++) {
        if (k < cnt) continue;
        int c1 = 1;
        for (int i = k; i >= k - cnt + 1; i--) c1 = mult(c1, i);
        c1 = mult(c1, pw(pw(n, cnt), mod - 2));
        c1 = mult(c1, dp[n][n - cnt]);
        if (cnt & 1) ans = sum(ans, c1);
        else ans = sub(ans, c1);
        // k! / (k - cnt)! * (n - 1)! / (n + cnt - 1)!
    }
    cout << ans;
    return 0;
}