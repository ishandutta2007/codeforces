#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = 1e6 + 10;
int dp[maxN];
int n;
int suf_sum[maxN];
int pw2[maxN];
void solve() {
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 0; i <= n + 1; i++) {
        suf_sum[i] = 0;
    }
    dp[n] = 1;
    suf_sum[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        int R = min(2 * i - 1, n);
        dp[i] = sub(suf_sum[i + 1], suf_sum[R + 1]);
        suf_sum[i] = sum(suf_sum[i + 1], dp[i]);
    }
    pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw2[i] = mult(2, pw2[i - 1]);
    }
    const int inv2 = (mod + 1) / 2;
    int res = 1;
    for (int i = 1; i <= n; i++) res = mult(res, inv2);
    for (int i = 1; i <= n; i++) {
        cout << mult(res, mult(2, mult(dp[i], pw2[i / 2]))) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}