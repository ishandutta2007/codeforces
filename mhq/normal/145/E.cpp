#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
const int maxN = (int)1e6 + 100;

int n, m;
int tp[maxN];

struct node{
    int cnt0, cnt1, val01, val10;
    node() : cnt0(-1), cnt1(-1), val01(-1), val10(-1) {}
    void flip() {
        swap(cnt0, cnt1);
        swap(val01, val10);
    }
};

node t[4 * maxN];
bool flipped[4 * maxN];

node merge(node a, node b) {
    if (a.cnt0 == -1) return b;
    else if (b.cnt0 == -1) return a;
    node c;
    c.cnt0 = a.cnt0 + b.cnt0;
    c.cnt1 = a.cnt1 + b.cnt1;
    c.val01 = max(a.cnt0 + b.val01, a.val01 + b.cnt1);
    c.val10 = max(a.cnt1 + b.val10, a.val10 + b.cnt0);
    return c;
}


void push(int v, int l, int r) {
    if (!flipped[v]) return ;
    if (l != r) {
        flipped[v] = false;
        flipped[v + v] ^= 1;
        flipped[v + v + 1] ^= 1;
        t[v + v].flip();
        t[v + v + 1].flip();
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].cnt0 = (tp[tl] == 0);
        t[v].cnt1 = (tp[tl] == 1);
        t[v].val01 = t[v].val10 = 1;
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = merge(t[v + v], t[v + v + 1]);
}

void upd(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r) return ;
    if (tl == l && tr == r) {
        flipped[v] = true;
        t[v].flip();
        push(v, tl, tr);
        return ;
    }
    int tm = (tl + tr) / 2;
    upd(v + v, tl, tm, l, min(tm, r));
    upd(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
    t[v] = merge(t[v + v], t[v + v + 1]);
}

node get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r) return {};
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return merge(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if (c == '4') tp[i] = 0;
        else tp[i] = 1;
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        if (s == "count") {
            cout << get(1, 1, n, 1, n).val01 << '\n';
        }
        else {
            int l, r;
            cin >> l >> r;
            upd(1, 1, n, l, r);
        }
    }
    return 0;
}