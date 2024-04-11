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
const int maxN = 2 * (int)1e5 + 100;
int fact[maxN];
int invfact[maxN];
int inv[maxN];
int cnk(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return mult(fact[a], mult(invfact[b], invfact[a - b]));
}
vector < int > divs[maxN];
int mob[maxN];
int lp[maxN];
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
    for (int i = 1; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) {
            divs[j].push_back(i);
        }
    }
    for (int i = 2; i < maxN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            for (int j = 2 * i; j < maxN; j += i) lp[j] = i;
        }
    }
    mob[1] = 1;
    for (int i = 2; i < maxN; i++) {
        int p = lp[i];
        if ((i / p) % p == 0) mob[i] = 0;
        else mob[i] = sub(0, mob[i / p]);
    }
    int q;
    cin >> q;
    while (q--) {
        int n, f;
        cin >> n >> f;
        int ans = 0;
        for (int v : divs[n]) {
            if (mob[v] == 0) continue;
            ans = sum(ans, mult(mob[v], cnk(n / v - 1, f - 1)));
        }
        cout << ans << '\n';
    }
    return 0;
}