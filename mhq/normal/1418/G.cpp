#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 5e5 + 10;
pair<int, int> t[4 * maxN];
int lazy[4 * maxN];

pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b) {
    pair<int, int> c;
    c.first = min(a.first, b.first);
    if (c.first == a.first) c.second += a.second;
    if (c.first == b.first) c.second += b.second;
    return c;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(0, 1);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void upd(int v, int by) {
    lazy[v] += by;
    t[v].first += by;
}

void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v] != 0) {
        upd(2 * v, lazy[v]);
        upd(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int by) {
    if (tr < l || r < tl) return;
    if (l <= tl && tr <= r) {
        upd(v, by);
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

pair < int, int > get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return make_pair(1e9, 0);
    if (l <= tl && tr <= r) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return merge(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}
vector < int > vals[maxN];
int pos[maxN];
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        vals[i].emplace_back(0);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        vals[a[i]].emplace_back(i);
        pos[i] = vals[a[i]].size() - 1;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int id = pos[i];
        upd(1, 1, n,  vals[a[i]][id - 1] + 1, i, +1);
        if (id >= 3) {
            upd(1, 1, n, vals[a[i]][id - 3] + 1, vals[a[i]][id - 2], -1);
        }
        if (id >= 4) {
            upd(1, 1, n, vals[a[i]][id - 4] + 1, vals[a[i]][id - 3], +1);
        }
        auto it = get(1, 1, n, 1, i);
        assert(it.first >= 0);
        if (it.first == 0) ans += it.second;
    }
    cout << ans;
    return 0;
}