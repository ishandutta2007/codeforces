#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 10;
int p[N];
int t[N];
int f[N];
int fact[N];
int n;
const int mod = (int)1e9 + 7;
const int inv2 = (mod + 1) / 2;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
void add(int i, int d) {
    for (; i <= n; i = (i | (i - 1)) + 1) {
        t[i] = sum(t[i], d);
    }
}
int fenw(int r) {
    int res = 0;
    while (r >= 1) {
        res = sum(res, t[r]);
        r = r & (r - 1);
    }
    return res;
}
int fenw(int l, int r) {
    return fenw(r) - fenw(l - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        fact[i] = mult(fact[i - 1], i);
        f[i] = mult(mult(inv2, mult(i, i - 1)), mult(inv2, fact[i]));
    }
    int s = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(p[i], 1);
        int x = fenw(p[i] - 1);
        x = p[i] - x - 1;
        ans = sum(ans, mult(x, f[n - i]));
        ans = sum(ans, mult(fact[n - i], mult(inv2, mult(x, x - 1))));
        ans = sum(ans, mult(fact[n - i], mult(x, s)));
        s = sum(s, x);
    }
    ans = sum(ans, s);
    cout << ans;
    /*f(n) = C(2, n) * n! / 2;
    a'
    (n - 1)! * (a * (a - 1) / 2) + f(n - 1) * (a - 1);
    a b
    a b'
    (n - 2)! * (_ < b) * (a - 1) +
    a b c d' ..
    (n - 4)! * (_ < d) * (_a + _b + _c) + f(n - 4) * _d +
    (n - 4)! (_d + 1) * (_d)/2*/
    return 0;
}