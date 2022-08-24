#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxN = 505;
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
int n, k;
int f[maxN];
int dp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int len = 1; len <= n; len++) {
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = max(i - len + 1, 1); j <= i; j++) {
                dp[i] = sum(dp[i], dp[j - 1]);
            }
        }
        f[len] = dp[n];
        for (int j = len - 1; j >= 0; j--) f[len] = sub(f[len], f[j]);
    }
    int ans = 0;
    for (int len1 = 1; len1 <= n; len1++) {
        for (int len2 = 1; len2 <= n; len2++) {
            if (len1 * len2 < k) ans = sum(ans, mult(f[len1], f[len2]));
        }
    }
    cout << mult(ans, 2);
    return 0;
}