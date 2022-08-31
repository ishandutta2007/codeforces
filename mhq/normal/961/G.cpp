#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
int w[maxN];
int n, k;
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
int invfact[maxN];
int fact[maxN];
int inv[maxN];
void calc() {
    inv[1] = 1;
    invfact[0] = 1;
    fact[0] = 1;
    fact[1] = 1;
    invfact[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(mod - (mod / i), inv[mod % i]);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int cnk(int n, int k) {
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
int get(int x) {
    if (x < 0) return 0;
    int cur = 0;
    for (int i = 0; i <= (k - 1); i++) {
        if ((k - 1 - i) & 1) {
            cur = sub(cur, mult(pw(i + 1, x), cnk(k - 1, i)));
        }
        else {
            cur = sum(cur, mult(pw(i + 1, x), cnk(k - 1, i)));
        }
    }
    //cout << cur << endl;
    cur = mult(cur, invfact[x]);
    return cur;
}
int main() {
    srand(time(0));
    calc();
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int S = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        S = sum(S, w[i]);
    }
    int p = sum(get(n - 1), get(n - 2));

    cout << mult(p, mult(mult(invfact[k - 1], fact[n - 1]), S));
}