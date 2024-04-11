#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

const int maxN = 2 * (int)1e5 + 100;

int fact[maxN], invfact[maxN], inv[maxN];

void init() {
    inv[1] = invfact[1] = invfact[0] = fact[0] = fact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}

int cnk(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}

int invNumber(int a) {
    return pw(a, mod - 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    init();
    int n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << 0;
        return 0;
    }
    cout << mult(pw(2, n - 3), mult(cnk(m, n - 1), n - 2));
    return 0;
}