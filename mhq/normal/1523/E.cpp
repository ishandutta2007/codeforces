#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
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
const int maxN = 2e5 + 10;
int inv[maxN];
int fact[maxN];
int invfact[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[n - k], invfact[k]));
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << n << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n && (k * i <= n + k - 1); i++) {
            //choose >= i;
            int all_ways = cnk(n, i);
            int good_ways = cnk(n + k - 1 - k * i + i, i);
            ans = sum(ans, mult(good_ways, pw(all_ways, mod - 2)));
        }
        ans = sum(ans, 1);
        cout << ans << '\n';
    }

    return 0;
}