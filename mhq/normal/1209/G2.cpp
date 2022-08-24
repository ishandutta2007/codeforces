//#define _GLIBCXX_DEBUG
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = 2e5 + 10;
set<int> ss[maxN];
int a[maxN];
int pref_max[4 * maxN];
int mn[4 * maxN];
int suf_max[4 * maxN];
int s[4 * maxN];
int mx[4 * maxN];
int lazy_add[4 * maxN];
int val[maxN];
void merge(int v) {
    if (mn[2 * v] < mn[2 * v + 1]) {
        s[v] = s[2 * v];
        mn[v] = mn[2 * v];
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        pref_max[v] = pref_max[2 * v];
        suf_max[v] = max(suf_max[2 * v], mx[2 * v + 1]);
    }
    else if (mn[2 * v] > mn[2 * v + 1]) {
        s[v] = s[2 * v + 1];
        mn[v] = mn[2 * v + 1];
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        pref_max[v] = max(mx[2 * v], pref_max[2 * v + 1]);
        suf_max[v] = suf_max[2 * v + 1];
    }
    else {
        s[v] = s[2 * v] + s[2 * v + 1] + max(pref_max[2 * v + 1], suf_max[2 * v]);
        mn[v] = mn[2 * v];
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        pref_max[v] = pref_max[2 * v];
        suf_max[v] = suf_max[2 * v + 1];
    }
}
void apply(int v, int x) {
    mn[v] += x;
    lazy_add[v] += x;
}
void push(int v, int tl, int tr) {
    if (lazy_add[v] != 0 && tl != tr) {
        apply(2 * v, lazy_add[v]);
        apply(2 * v + 1, lazy_add[v]);
    }
    lazy_add[v] = 0;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        mn[v] = 0;
        pref_max[v] = val[tl];
        suf_max[v] = 0;
        s[v] = 0;
        mx[v] = val[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    merge(v);
}
void chVal(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        pref_max[v] = val[tl];
        suf_max[v] = 0;
        s[v] = 0;
        mx[v] = val[tl];
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm) chVal(2 * v, tl, tm, pos);
    else chVal(2 * v + 1, tm + 1, tr, pos);
    merge(v);
}
void upd(int v, int tl, int tr, int l, int r, int by) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        apply(v, by);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    merge(v);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  //  freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ss[a[i]].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (*ss[a[i]].begin() == i) {
            val[i] = ss[a[i]].size();
        }
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (*ss[a[i]].begin() == i) {
            upd(1, 1, n, i, n, +1);
        }
        if (*(--ss[a[i]].end()) == i) {
            upd(1, 1, n, i, n, -1);
        }
    }
    assert(mn[1] == 0 && suf_max[1] == 0);
    cout << n - (s[1] + pref_max[1]) << endl;
    auto change = [&](int color, int d) {
        assert(!ss[color].empty());
        upd(1, 1, n, *ss[color].begin(), n, d);
        upd(1, 1, n, *(--ss[color].end()), n, -d);
        if (d == 1) {
            val[*ss[color].begin()] = ss[color].size();
            chVal(1, 1, n, *ss[color].begin());
        }
        else {
            val[*ss[color].begin()] = 0;
            chVal(1, 1, n, *ss[color].begin());
        }
    };
    while (q--) {
        int pos, to;
        cin >> pos >> to;
        if (a[pos] != to) {
            change(a[pos], -1);
            if (!ss[to].empty()) {
                change(to, -1);
            }
            ss[a[pos]].erase(pos);
            if (!ss[a[pos]].empty()) {
                change(a[pos], +1);
            }
            ss[to].insert(pos);
            change(to, +1);
            a[pos] = to;
        }
        assert(mn[1] == 0 && suf_max[1] == 0);
        cout << n - (s[1] + pref_max[1]) << '\n';
    }
    return 0;
}