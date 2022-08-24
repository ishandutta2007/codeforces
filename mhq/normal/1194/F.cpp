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
const int maxN = 2 * (int)1e5 + 100;
int fact[maxN], invfact[maxN], inv[maxN];
int cnk(int n, int k) {
    if (n - k < 0 || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int n, k;
ll T;
ll t[maxN];
int pw2[maxN];
int inv2[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = inv[1] = fact[1] = invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
        fact[i] = mult(fact[i - 1], i);
    }
    pw2[0] = 1;
    inv2[0] = 1;
    for (int i = 1; i < maxN; i++) {
        pw2[i] = mult(2, pw2[i - 1]);
        inv2[i] = mult(inv[2], inv2[i - 1]);
    }
    int add = 1;
    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> t[i];
    ll total = T;
    int sm = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll prv = total;
        total -= t[i];
        if (total < 0) break;
        if (total >= i) {
            add = pw2[i];
        }
        else {
            add = mult(2, add);
            ll cp = min(prv, (ll)i);
            while (cp > total) {
                add = sub(add, cnk(i, cp));
                cp--;
            }
            if (prv < i) add = sub(add, cnk(i - 1, prv));
        }
        ans = sum(ans, mult(add, inv2[i]));
    }
    cout << ans;
    return 0;
}