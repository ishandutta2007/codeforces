#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
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
int n, k;
const int maxN = 2 * (int)1e5 + 100;
int h[maxN];
int fact[maxN], invfact[maxN], inv[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[n - k], invfact[k]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    inv[1] = fact[0] = fact[1] = invfact[0] = invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    h[n + 1] = h[1];
    int coef = 1;
    if (k == 1) {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] == h[i + 1]) {
            coef = mult(coef, k % mod);
        }
        else {
            cnt++;
        }
    }
    int total = pw(k % mod, cnt);
//    cout << cnt << " " << coef << " " << total << endl;
    int ways = 0;
    for (int c = 0; 2 * c <= cnt; c++) {
        ways = sum(ways, mult(pw(k - 2, cnt - 2 * c), mult(cnk(cnt, c), cnk(cnt - c, c))));
//        cout << "UPD " << ways << endl;
    }
//    cout << ways << "  gg " << endl;
    total = sub(total, ways);
    cout << mult(total, mult(inv[2], coef));
    return 0;
}