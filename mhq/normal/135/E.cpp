#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 2 * (int)1e6 + 100;
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int cnk(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return mult(fact[a], mult(invfact[b], invfact[a - b]));
}
int k, w;
int ways(int w) {
    if (w < 0) return 0;
    int ans = 0;
    for (int add = 1; add <= k; add++) {
        if (w > k) continue;
        int coef = mult(fact[add], cnk(k, add));
        int coef2 = mult(cnk(k - add, w), fact[w]);
        ans = sum(ans, mult(coef, mult(coef2, coef2)));
    }
    for (int add = max(0, w - k); add <= w; add++) {
        int coef = pw(k, add);
        int coef2 = mult(cnk(k, w - add), fact[w - add]);
        ans = sum(ans, mult(coef, mult(coef2, coef2)));
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    fact[0] = invfact[0] = inv[1] = fact[1] = invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> k >> w;
    cout << sum(pw(k, w - 1), sub(ways(w), ways(w - 1)));
    return 0;
}