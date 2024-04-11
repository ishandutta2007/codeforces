#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
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
const int inv3 = (mod + 1) / 3;
const int maxN = 3e6 + 228;
int inv[maxN];
int fact[maxN];
int invfact[maxN];
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int getF(int x) {
    int s = 0;
    for (int i = 3; i <= 3 * n; i += 3) {
        s = sum(s, cnk(i, x));
    }
    return s;
}
int f[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    assert(mult(inv3, 3) == 1);
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    for (int x = 1; x <= 3; x++) {
        f[x] = getF(x);
    }
    for (int i = 4; i <= 3 * n + 1; i++) {
        int D = cnk(3 * n + 3, i);
        D = sub(D, f[i - 3]);
        D = sub(D, mult(3, f[i - 2]));
        f[i - 1] = mult(D, inv3);
    }
    while (q--) {
        int z;
        cin >> z;
        cout << f[z] << '\n';
    }
    return 0;
}