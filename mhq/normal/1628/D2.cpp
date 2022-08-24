#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
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
int m, k;
const int maxN = 2e6 + 10;
int inv[maxN];
int fact[maxN];
int invfact[maxN];
int inv2[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
void solve() {
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int coef = mult(cnk(m - i + n - m, n - m), inv2[n - i]);
        if (i < m) {
            coef = sub(coef, mult(cnk(m - i - 1 + n - m, n - m), inv2[n - i]));
        }

        ans = sum(ans, mult(coef, mult(k, i)));
    }
    cout << ans << '\n';
}
const int inv_2 = (mod + 1) / 2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);

    fact[0] = invfact[0] = inv[1] = fact[1] = invfact[1] = 1;
    inv2[0] = 1;
    for (int i = 1; i < maxN; i++) inv2[i] = mult(inv_2, inv2[i - 1]);
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}