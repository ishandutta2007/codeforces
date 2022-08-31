#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, k;
const int maxN = 6e5 + 1488;
ll t[4 * maxN];
ll lazy[4 * maxN];
void upd(int v, ll by) {
    lazy[v] += by;
    t[v] += by;
}
void merge(int v) {
    t[v] = max(t[2 * v], t[2 * v + 1]);
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v] != 0) {
        upd(2 * v, lazy[v]);
        upd(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, ll by) {
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
        upd(v, by);
        push(v, tl, tr);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) /  2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    merge(v);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = tl;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    merge(v);
}
const ll INF = 1e18;
ll get(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl) return -INF;
    push(v, tl, tr);
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k >> m;
    multiset < int > ss;
    set < pair < int, int > > s;
    int N = 2 * n + m + 5;
    build(1, 1, N);
    auto del =[&](int c) {
        ss.erase(ss.find(c));
        upd(1, 1, N, 1, c, -1);
    };
    auto add =[&](int c) {
        ss.insert(c);
        upd(1, 1, N, 1, c, +1);
    };
    while (m--) {
        int x, y;
        cin >> x >> y;
        int py = (x <= k ? (k - x + y) : (y + x - k));
        if (s.count(make_pair(x, y))) {
            s.erase(make_pair(x, y));
            del(py);
        }
        else {
            s.insert(make_pair(x, y));
            add(py);
        }
        if (ss.empty()) {
            cout << 0 << '\n';
        }
        else {
            auto it = *(--ss.end());
            cout << max(0LL, get(1, 1, N, 1, it) - 1 - n) << '\n';
        }
    }


    return 0;
}