#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int m;
const int mod = 998244353;
const int maxN = 3e5 + 10;
int dp[maxN];
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
int fact[maxN], invfact[maxN], inv[maxN];
int on_pairs[maxN];
int f[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
void solve() {
    cin >> n;
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    for (int i = 0; i <= n; i++) {
        on_pairs[i] = f[i] = 0;
    }
    on_pairs[0] = 1;
    for (int i = 2; i <= n; i += 2) {
        on_pairs[i] = mult(i - 1, mult(2, on_pairs[i - 2]));
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = sum(f[i], f[i - 1]);
        if (i >= 2) {
            f[i] = sum(f[i], mult(i - 1, f[i - 2]));
        }
    }
    int ans = 0;
    for (int cnt = 0; 2 * cnt <= n; cnt += 2) {
        int coef = mult(cnk(n - cnt, cnt), on_pairs[cnt]);
        coef = mult(coef, f[n - 2 * cnt]);
        ans = sum(ans, coef);
    }
    cout << ans << '\n';


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();

    }
    return 0;
}