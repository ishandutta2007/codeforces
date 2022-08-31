#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)5e5 + 10;
int n, q;
char s[maxN];
struct node{
    int to_left;
    int to_right;
    int tp_left;
    int tp_right;
    int max_ans;
    int sz;
    int f01, f10;
    int lele;
    int riri;
    node() {
        to_left = 0;
        to_right = 0;
        max_ans = 0;
        sz = 0;
        tp_left = 0;
        tp_right = 0;
        f01 = 0;
        f10 = 0;
        lele = 0;
        riri = 0;
    }
};
const int LEFT = 0;
const int RIGHT = 1;
node t[4 * maxN];
bool flip[4 * maxN];
node merge(const node& a, const node& b) {
//    cout << " MERGEING " << a.sz << " " << b.sz << " " << a.max_ans << " " << b.max_ans << " " << a.tp_left << " " << b.tp_left << endl;
//    cout << " CONT " << a.tp_right << " " << b.tp_right << endl;
    node c;
    c.sz = a.sz + b.sz;
    c.max_ans = max(a.max_ans, b.max_ans);
    c.tp_left = a.tp_left;
    c.to_left = a.to_left;
    if (a.to_left == a.sz) {
        if (a.tp_right == b.tp_left) {
            c.to_left += b.to_left;
            c.lele = b.lele;
        }
        else {
            c.lele = b.to_left;
        }
    }
    else {
        c.lele = a.lele;
        if (a.to_left + a.lele == a.sz && a.tp_right == b.tp_left) {
            c.lele += b.to_left;
        }
    }

    c.tp_right = b.tp_right;
    c.to_right = b.to_right;

    if (b.to_right == b.sz) {
        if (b.tp_right == a.tp_right) {
            c.to_right += a.to_right;
            c.riri = a.riri;
        }
        else {
            c.riri = a.to_right;
        }
    }
    else {
        c.riri = b.riri;
        if (b.to_right + b.riri == b.sz && b.tp_left == a.tp_right) {
            c.riri += a.to_right;
        }
    }
    c.max_ans = max(c.max_ans, max(c.to_left, c.to_right));
    //f01
    c.f01 = max(a.f01, b.f01);
    c.f10 = max(a.f10, b.f10);
    if (a.tp_right == b.tp_left) {
        if (a.tp_right == LEFT) {
            c.f01 = max(c.f01, a.riri + a.to_right + b.to_left);
            c.f10 = max(c.f10, b.lele + a.to_right + b.to_left);
        }
        else {
            c.f01 = max(c.f01, b.lele + b.to_left + a.to_right);
            c.f10 = max(c.f10, a.riri + a.to_right + b.to_left);
        }
    }
    else {
        if (a.tp_right == RIGHT) {
            c.f01 = max(c.f01, a.to_right + b.to_left);
        }
        else {
            c.f10 = max(c.f10, a.to_right + b.to_left);
        }
    }
    if (c.tp_left == RIGHT) {
        c.f01 = max(c.f01, c.to_left + c.lele);
    }
    else {
        c.f10 = max(c.f10, c.to_left + c.lele);
    }
    if (c.tp_right == RIGHT) {
        c.f10 = max(c.f10, c.to_right + c.riri);
    }
    else {
        c.f01 = max(c.f01, c.to_right + c.riri);
    }
//    cout << " GOT " << c.max_ans << endl;
    return c;
}

void apply(int v) {
    flip[v] ^= 1;
    t[v].tp_right ^= 1;
    t[v].tp_left ^= 1;
    swap(t[v].f01, t[v].f10);
}

void push(int v, int tl, int tr) {
    if (tl != tr && flip[v]) {
        apply(2 * v);
        apply(2 * v + 1);
    }
    flip[v] = false;
}

void merge(int v) {
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].to_left = t[v].to_right = t[v].sz = t[v].max_ans = 1;
        if (s[tl] == '<') {
            t[v].tp_right = t[v].tp_left = LEFT;
        }
        else {
            t[v].tp_right = t[v].tp_left = RIGHT;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    merge(v);
}

void upd(int v, int tl, int tr, int l, int r) {
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        apply(v);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r);
    upd(2 * v + 1, tm + 1, tr, l, r);
    merge(v);
}

node get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(2 * v, tl, tm, l, r);
    else if (l > tm) return get(2 * v + 1, tm + 1, tr, l, r);
    else return merge(get(2 * v, tl, tm, l, tm), get(2 * v + 1, tm + 1, tr, tm + 1, r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    s[0] = '>';
    s[n + 1] = '<';
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    build(1, 0, n + 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        upd(1, 0, n + 1, l, r);
        auto nt = get(1, 0, n + 1, l, r);
//        cout << " WHAT " << max(nt.f01, nt.f10) << endl;
        cout << max(nt.max_ans, nt.f01) << '\n';
    }
    return 0;
}