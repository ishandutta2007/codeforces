#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 4 * (int)1e5 + 10;
int t[4 * maxN];
int lazy[4 * maxN];
ll msk[4 * maxN];
ll lazymsk[4 * maxN];
const int mod = (int)1e9 + 7;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
void push(int v, int tl, int tr) {
    if (lazy[v] == 1 && lazymsk[v] == 0) {
        return ;
    }
    msk[v] |= lazymsk[v];
    t[v] = mult(t[v], pw(lazy[v], tr - tl + 1));
    if (tl < tr) {
        lazy[2 * v] = mult(lazy[2 * v], lazy[v]);
        lazymsk[2 * v] |= lazymsk[v];
    }
    if (tl < tr) {
        lazy[2 * v + 1] = mult(lazy[2 * v + 1], lazy[v]);
        lazymsk[2 * v + 1] |= lazymsk[v];
    }
    lazy[v] = 1;
    lazymsk[v] = 0;
}
pair < int, ll > get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (tl == l && tr == r) {
        return {t[v], msk[v]};
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(v + v, tl, tm, l, r);
    else if (l > tm) return get(v + v + 1, tm + 1, tr, l, r);
    else {
        auto t1 = get(v + v, tl, tm, l, tm);
        auto t2 = get(v + v + 1, tm + 1, tr, tm + 1, r);
        return {mult(t1.first, t2.first), t1.second | t2.second};
    }
}
void upd(int v, int tl, int tr, int l, int r, int coef, ll msk2) {
    push(v, tl, tr);
    if (l > r) return ;
    if (tl == l && tr == r) {
        lazy[v] = coef;
        lazymsk[v] = msk2;
        push(v, tl, tr);
        return ;
    }
    int tm = (tl + tr) / 2;
    upd(v + v, tl, tm, l, min(r, tm), coef, msk2);
    upd(v + v + 1, tm + 1, tr, max(tm + 1, l), r, coef, msk2);
    t[v] = mult(t[v + v], t[v + v + 1]);
    msk[v] = msk[v + v] | msk[v + v + 1];
}
int a[maxN];
vector < int > divs[305];
void build(int v, int tl, int tr) {
    lazy[v] = 1;
    lazymsk[v] = 0;
    if (tl == tr) {
        t[v] = a[tl];
        for (int j : divs[a[tl]]) {
            msk[v] |= (1LL << j);
        }
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = mult(t[v + v], t[v + v + 1]);
    msk[v] = msk[v + v] | msk[v + v + 1];
}
int n, q;
vector < int > pr;
bool used[305];
int what[65];
void init() {
    for (int i = 2; i <= 300; i++) {
        if (used[i]) continue;
        pr.push_back(i);
        what[pr.size() - 1] = mult(i - 1, pw(i, mod -  2));
        for (int j = i; j <= 300; j += i) {
            used[j] = true;
            divs[j].push_back(pr.size() - 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        string s;
        cin >> s;
        int l, r;
        cin >> l >> r;
        if (s == "MULTIPLY") {
            ll msk = 0;
            int x;
            cin >> x;
            for (int j : divs[x]) {
                msk |= (1LL << j);
            }
            upd(1, 1, n, l, r, x, msk);
        }
        else {
            auto t = get(1, 1, n, l, r);
            for (int j = 0; j < 62; j++) {
                if (t.second & (1LL << j)) {
                    t.first = mult(t.first, what[j]);
                }
            }
            cout << t.first << '\n';
        }
    }
}