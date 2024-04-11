#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxN = (int)1e6 + 10;
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
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int pwk[maxN];
int pw3[maxN];
int pw1_n[maxN];
int cnk(int n, int k) {
    if (n < k) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    inv[1] = 1;
    invfact[0] = 1;
    fact[0] = 1;
    invfact[1] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = mult(mod - (mod / i), inv[mod % i]);
        invfact[i] = mult(invfact[i - 1], inv[i]);
        fact[i] = mult(fact[i - 1], i);
    }
    pw3[0] = 1;
    for (int i = 1; i <= n; i++) pw3[i] = mult(3, pw3[i - 1]);
    pwk[0] = 1;
    pwk[1] = pw(3, n);
    for (int i = 2; i <= n; i++) {
        pwk[i] = mult(pwk[i - 1], pwk[1]);
    }
    pw1_n[1] = 0;
    for (int i = 2; i <= n; i++) {
        pw1_n[i] = pw(sub(pw3[i], 1), n);
    }
    int ans = mult(2, sub(pwk[n], pw(sub(pw3[n], 3), n)));
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        int f = sub(pwk[n - i], pw(sub(pw(3, n - i), 1), n));
        if (i & 1) cur = sum(cur, mult(cnk(n, i), f));
        else cur = sub(cur, mult(cnk(n, i), f));
    }
    ans = sub(ans, mult(cur, 3));
    cout << ans;
	return 0;
}