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
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = (int)1e5 + 100;
int dp[maxN];
int calc(int x) {
    dp[0] = 2;
    dp[1] = 2;
    for (int i = 2; i <= x; i++) {
        dp[i] = 0;
        dp[i] = sum(dp[i], dp[i - 1]);
        dp[i] = sum(dp[i], dp[i - 2]);
    }
    return dp[x];
}
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int f1 = calc(n);
    int f2 = calc(m);
    int ans = sum(f1, f2);
    ans -= 2;
    if (ans < 0) ans += mod;
    cout << ans;
    return 0;
}