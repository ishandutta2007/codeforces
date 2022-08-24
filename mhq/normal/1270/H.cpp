#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int INF = (int)1e6 + 10;
const int maxN = (int)1e6 + 100;
const int maxT = INF + 10;
int n, q;
int a[maxN];

pair < int, int > t[4 * maxT];
int lazy[4 * maxT];

void push(int v) {
    if (lazy[v]) {
        for (int j = 2 * v; j < 2 * v + 2; j++) {
            lazy[j] += lazy[v];
            t[j].first += lazy[v];
        }
        lazy[v] = 0;
    }
}

pair < int, int > merge(pair < int, int > a, pair < int, int > b) {
    if (a.first < b.first) return a;
    else if (a.first > b.first) return b;
    else return make_pair(a.first, a.second + b.second);
}

void upd(int v, int tl, int tr, int l, int r, int by) {
    if (l <= tl && tr <= r) {
        lazy[v] += by;
        t[v].first += by;
        return;
    }
    if (r < tl || l > tr) return;
    push(v);
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, by);
    upd(2 * v + 1, tm + 1, tr, l, r, by);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void set_pos(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v].first = val;
        t[v].second = 1;
        return;
    }
    push(v);
    int tm = (tl + tr) /  2;
    if (pos <= tm) set_pos(2 * v, tl, tm, pos, val);
    else set_pos(2 * v + 1, tm + 1, tr, pos, val);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

pair < int, int > get(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
        return t[v];
    }
    if (r < tl || l > tr) return make_pair(10 * INF, 0);
    push(v);
    int tm = (tl + tr) / 2;
    return merge(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

bool has[maxT];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        if (has[tl]) t[v] = make_pair(0, 1);
        else t[v] = make_pair(INF, 1);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void go(int x, int y, int by) {
    if (x < y) swap(x, y);
    // we have 10 if (x >= h > y)
    upd(1, 1, INF + 1, y + 1, x, by);
}


int where[maxT];

int get_coef(int x, int y, int z) {
    return (max(x, y) >= z && z > min(x, y)) ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(where, -1, sizeof where);
    a[0] = INF;
    a[n + 1] = 0;
    for (int i = 0; i <= n; i++) {
        has[a[i]] = true;
        where[a[i]] = i;
    }

    // if h >= a[i] -> f[i] = 0, else f[i] = 1

    build(1, 1, INF + 1);
    a[n + 1] = 0;
    set < int > s;
    for (int i = 0; i <= n; i++) {
        s.insert(a[i]);
    }
    for (int i = 0; i <= n; i++) {
        assert(a[i] != a[i + 1]);
        go(a[i], a[i + 1], 1);
    }


    while (q--) {
        int pos, x;
        cin >> pos >> x;
        //assert(!s.count(x));
        int p = *s.lower_bound(x);
        int his_pos = where[p];
        assert(his_pos != -1);
        int his_val = get(1, 1, INF + 1, p, p).first;
        set_pos(1, 1, INF + 1, a[pos], 10 * INF);
        set_pos(1, 1, INF + 1, x, his_val);
        for (int it = -1; it <= 1; it += 2) {
            int npos = pos + it;
            if (npos < 0 || npos > n + 1) continue;
            go(a[pos], a[npos], -1);
            go(x, a[npos], 1);
        }
        where[a[pos]] = -1;
        s.erase(a[pos]);
        a[pos] = x;
        where[a[pos]] = pos;
        s.insert(a[pos]);
        auto it = get(1, 1, INF + 1, 1, INF + 1);
        cout << it.second - 1 << '\n';
    }
    return 0;
}