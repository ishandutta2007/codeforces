#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll D;
const int maxN = 65;
int fact[maxN];
int invfact[maxN];
const int mod = 998244353;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
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
    cin >> D;
    vector < ll > pr;
    for (ll i = 2; i * i <= D; i++) {
        if (D % i == 0) {
            while (D % i == 0) {
                pr.emplace_back(i);
                D /= i;
            }
        }
    }
    if (D > 1) pr.emplace_back(D);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = pw(fact[i], mod - 2);
    }
    int q;
    cin >> q;
    while (q--) {
        ll u, v;
        cin >> u >> v;
        int c1 = 1; int c2 = 1;
        int ex1 = 0;
        int ex2 = 0;
        for (ll p : pr) {
            int p1 = 0;
            int p2 = 0;
            while (u % p == 0) {
                u /= p;
                p1++;
            }
            while (v % p == 0) {
                v /= p;
                p2++;
            }
            if (p1 == p2) continue;
            if (p1 < p2) {
                ex1 += p2 - p1;
                c1 = mult(c1, invfact[p2 - p1]);
            }
            else {
                ex2 += p1 - p2;
                c2 = mult(c2, invfact[p1 - p2]);
            }
        }
        c1 = mult(c1, fact[ex1]);
        c2 = mult(c2, fact[ex2]);
        cout << mult(c1, c2) << '\n';
    }
    return 0;
}