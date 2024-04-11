#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int get_inv(int a) {
    return pw(a, mod - 2);
}
const int maxK = (int)1e5 + 10;
int fact[maxK], invfact[maxK], inv[maxK];
int n, m, a, b, k, p, q;
int cnk(int x, int y) {
    if (y > x) return 0;
    return mult(fact[x], mult(invfact[x - y], invfact[y]));
}
const int maxN = 1505;
int T[maxN];
int F[maxN];
int p_pow[maxK], q_pow[maxK];
int prefF[maxN];
void init() {
    cin >> n >> m >> a >> b >> k;
    fact[0] = 1;
    invfact[0] = 1;
    inv[1] = 1;
    fact[1] = 1;
    invfact[1] = 1;
    for (int i = 2; i < maxK; i++) {
        inv[i] = mult(mod - mod / i, inv[mod % i]);
        fact[i] = mult(fact[i - 1], i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    p = mult(a, get_inv(b));
    q = sub(1, p);
    p_pow[0] = 1;
    q_pow[0] = 1;
    for (int i = 1; i <= k; i++) {
        p_pow[i] = mult(p_pow[i - 1], p);
        q_pow[i] = mult(q_pow[i - 1], q);
    }
    for (int i = 0; i <= m; i++) {
        F[i] = mult(cnk(k, i), mult(p_pow[i], q_pow[k - i]));
        prefF[i] = F[i];
        if (i >= 1) prefF[i] = sum(prefF[i - 1], prefF[i]);
    }
    T[m] = 1;
}
int nxtT[maxN];
int prefTF[maxN];
int prefT[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    for (int iter = 1; iter <= n; iter++) {
        for (int j = 0; j <= m; j++) {
            prefTF[j] = mult(F[j], T[j]);
            prefT[j] = T[j];
            if (j >= 1) {
                prefTF[j] = sum(prefTF[j - 1], prefTF[j]);
                prefT[j] = sum(prefT[j - 1], prefT[j]);
            }
        }
        int S = T[m];
        nxtT[0] = 0;
        for (int j = 1; j <= m; j++) {
            nxtT[j] = nxtT[j - 1];
            nxtT[j] = sum(nxtT[j], mult(S, mult(F[m - j], prefF[j - 1])));
            nxtT[j] = sub(nxtT[j], mult(F[m - j], prefTF[j - 1]));
            nxtT[j] = sub(nxtT[j], mult(prefF[j - 1], mult(F[m - j], T[m - j])));
        }
        for (int j = 0; j <= m; j++) {
            T[j] = nxtT[j];
        }
    }
    cout << T[m];
    return 0;
}