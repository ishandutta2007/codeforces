/*
    25.03.2019 16:28:59
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

using T = int;

struct segtree {
    vector< T > tree;
    int n;

    segtree(int size) : n(size), tree(size * 4, T()) {}
    segtree(vector< T >& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    void build(vector< T >& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    void set(int ind, T k, int i, int l, int r) {
        while (l < r) {
            int m = (l + r) / 2;
            if (ind <= m) {
                r = m;
                i = 2 * i + 1;
            } else {
                l = m + 1;
                i = 2 * i + 2;
            }
        }
        tree[i] = k;
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
        }
    }

    void set(int ind, T k) {
        set(ind, k, 0, 0, n - 1);
    }

    T ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) / 2;
        if (r <= m) {
            return ask(l, r, 2 * i + 1, vl, m);
        }
        if (l > m) {
            return ask(l, r, 2 * i + 2, m + 1, vr);
        }
        return ask(l, m, 2 * i + 1, vl, m) + ask(m + 1, r, 2 * i + 2, m + 1, vr);
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(l, r, 0, 0, n - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segtree tr(n), tp(n), ts(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') tr.set(i, 1);
        else if (s[i] == 'P') tp.set(i, 1);
        else ts.set(i, 1);
    }
    set<int> sr, sp, ss;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') sr.insert(i);
        else if (s[i] == 'P') sp.insert(i);
        else ss.insert(i);
    }
    for (int i = 0; i < q + 1; ++i) {
        if (i != 0) {
            int ind;
            char c;
            cin >> ind >> c;
            --ind;
            if (s[ind] != c) {
                if (s[ind] == 'R') {
                    tr.set(ind, 0);
                    sr.erase(ind);
                } else if (s[ind] == 'P') {
                    tp.set(ind, 0);
                    sp.erase(ind);
                } else {
                    ts.set(ind, 0);
                    ss.erase(ind);
                }
            }
            if (c == 'R') {
                tr.set(ind, 1);
                sr.insert(ind);
            } else if (c == 'P') {
                tp.set(ind, 1);
                sp.insert(ind);
            } else {
                ts.set(ind, 1);
                ss.insert(ind);
            }
            s[ind] = c;
        }
        int ans = 0;
        if (ss.empty()) {
            ans += tp.ask(0, n - 1);
        } else {
            if (!sr.empty()) {
                ans += tp.ask(*sr.begin(), *--sr.end());
                ans += tp.ask(max(*--ss.end(), *--sr.end()), n - 1);
                ans += tp.ask(0, min(*ss.begin(), *sr.begin()));
            } else {
            }
        }
        if (sp.empty()) {
            ans += tr.ask(0, n - 1);
        } else {
            if (!ss.empty()) {
                ans += tr.ask(*ss.begin(), *--ss.end());
                ans += tr.ask(max(*--sp.end(), *--ss.end()), n - 1);
                ans += tr.ask(0, min(*sp.begin(), *ss.begin()));
            } else {
            }
        }
        if (sr.empty()) {
            ans += ts.ask(0, n - 1);
        } else {
            if (!sp.empty()) {
                ans += ts.ask(*sp.begin(), *--sp.end());
                ans += ts.ask(max(*--sr.end(), *--sp.end()), n - 1);
                ans += ts.ask(0, min(*sr.begin(), *sp.begin()));
            } else {
            }
        }
        cout << ans << '\n';
    }
    return 0;
}