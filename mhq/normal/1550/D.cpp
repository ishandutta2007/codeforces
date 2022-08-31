#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5 + 10;
int fact[maxN];
int invfact[maxN];
int inv[maxN];
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int solve(int n, int l, int r) {
    int lim = min(r - n, 1 - l);
    int coef = 1;
    if (n % 2 == 1) coef = 2;
    int cnt_good = mult(coef, mult(lim, cnk(n, n / 2)));
    //cout << cnt_good << " ? " << lim << endl;;
    for (int p = lim + 1; p <= lim + 2 * n; p++) {
        int f1 = max(l + p, 1);
        int f2 = min(r - p, n);
        int g1 = f1 - 1;
        int g2 = n - f2;
        if (g1 > (n + 1) / 2 || g2 > (n + 1) / 2) break;
     //   cout << g1 << " " << g2 << endl;
        cnt_good = sum(cnt_good, cnk(n - g1 - g2, n / 2 - g1));
        if (n % 2 == 1) cnt_good = sum(cnt_good, cnk(n - g1 - g2, n / 2 - g2));
    }
    return cnt_good;
}
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    fact[0] = invfact[0] = invfact[1] = fact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n, l, r;
        cin >> n >> l >> r;
        int ans = solve(n, l, r);
        //cout << ans << " ??? " << endl;
        cout << ans << '\n';
    }
}