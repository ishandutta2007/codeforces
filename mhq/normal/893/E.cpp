#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e6 + 5;
const int MOD = (int)1e9 + 7;
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int n ,q;
int add(int a, int b) {
    int s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) {
        return mult(a, mult(pw(a, b / 2), pw(a, b / 2)));
    }
    else return mult(pw(a, b / 2), pw(a, b / 2));
}
void precalc() {
    inv[1] = 1;
    invfact[0] = 1;
    invfact[1] = 1;
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= maxN - 2; i++) {
        inv[i] = mult((MOD / i), (MOD - inv[MOD % i]));
        invfact[i] = mult(invfact[i  - 1], inv[i]);
        fact[i] = mult(fact[i - 1], i);
    }
}
int cnk(int k, int n) {
    return mult(mult(fact[n], invfact[n - k]), invfact[k]);
}
int solve (int n, int y) {
    //cout << n;
    int ans = pw(2, y - 1);
    //cout << ans << " gjlf";
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int tp = 0;
            while (n % i == 0) {
                n = n / i;
                tp++;
            }
            //cout << i << " " << tp << '\n';
            ans = mult(ans, cnk(tp, y + tp - 1));
        }
    }
    if (n != 1) ans = mult(ans, y);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    precalc();
    //cout << fact[3] << " " << invfact[2] << '\n';
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << '\n';
    }
    return 0;
}