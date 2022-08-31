#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, mod, l, r;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
int sum(int a, int b) {
    return ((ll)a + b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = (int)1e5 + 100;
vector < pair < int, int > > pr[maxN];
bool is_prime[maxN];
int lp[maxN];
int cnt[4 * maxN];
int t[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        cnt[v] = 0;
        t[v] = 1 % mod;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = mult(t[2 * v], t[2 * v + 1]);
}
void upd(int v, int tl, int tr, int pos, int by) {
    if (tl == tr) {
        cnt[v] += by;
        assert(cnt[v] >= 0);
        t[v] = pw(tl, cnt[v]);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos, by);
    else upd(2 * v + 1, tm + 1, tr, pos, by);
    t[v] = mult(t[2 * v], t[2 * v + 1]);
}
void upd(int x, int by) {
    for (auto it : pr[x]) {
        upd(1, 1, n, it.first, it.second * by);
    }
}
int c[maxN];
int val[2][maxN];
void calc(int ind, int x) {
    build(1, 1, n);
    val[ind][0] = (x <= 1) % mod;
    int prvL = 0;
    for (int i = 1; i <= n; i++) {
        upd(i, 1);
        upd(i - prvL, -1);
        int nxtL = min(i, (i + x) / 2);
        if (prvL < nxtL) {
            upd(i - prvL, 1);
            upd(nxtL, -1);
            prvL = nxtL;
        }
        if ((i + x) / 2 <= i) val[ind][i] = t[1];
        else val[ind][i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> mod >> l >> r;
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            is_prime[i] = true;
            lp[i] = i;
            for (int j = 2 * i; j <= n; j += i) lp[j] = i;
        }
        int p = lp[i];
        int cp = i;
        int ex = 0;
        while (cp % p == 0) {
            cp /= p;
            ex++;
        }
        pr[i].emplace_back(p, ex);
        for (auto it : pr[cp]) pr[i].emplace_back(it);
    }
    build(1, 1, n);
    c[0] = t[1];
    for (int i = 1; i <= n; i++) {
        upd(n - i + 1, 1);
        upd(i, -1);
        c[i] = t[1];
    }
    calc(0, l + 1);
    calc(1, r + 2);
    int total = 0;
    for (int i = 0; i <= n; i++) {
        total = sum(total, mult(c[i], sub(val[0][i], val[1][i])));
    }
    cout << total;
    return 0;
}