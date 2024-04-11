#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e6 + 5;
const int X = 1e6;

int n, m;
int a[N], b[N];

int pu[4 * N];
int mx[4 * N];
int vl[4 * N];
int cnt[X];

void inc(int v, int x) {
    pu[v] += x;
    mx[v] += x;
    vl[v] += x;
}

void push(int v) {
    inc(v << 1, pu[v]);
    inc(v << 1 | 1, pu[v]);
    pu[v] = 0;
}

void merge(int v) {
    mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l <= tl && tr <= r) {
        inc(v, x);
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (l <= tm) {
            update(v << 1, tl, tm, l, r, x);
        }
        if (r > tm) {
            update(v << 1 | 1, tm + 1, tr, l, r, x);
        }
        merge(v);
    }
}

int query(int v, int tl, int tr) {
    if (mx[v] <= 0) return -1;
    if (tl == tr) {
        return tl;
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        int res = query(v << 1 | 1, tm + 1, tr);
        if (res == -1) {
            res = query(v << 1, tl, tm);
        }
        merge(v);
        return res;
    }
}

void put(int v, int tl, int tr, int pos, int dx) {
    if (tl == tr) {
        cnt[tl] += dx;
        mx[v] = cnt[tl] ? vl[v] : -inf;
    } else {
        int tm = (tl + tr) >> 1;
        push(v);
        if (pos <= tm) {
            put(v << 1, tl, tm, pos, dx);
        } else {
            put(v << 1 | 1, tm + 1, tr, pos, dx);
        }
        merge(v);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fill(mx, mx + 4 * N, -inf);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        update(1, 1, X, 1, a[i], 1);
        put(1, 1, X, a[i], +1);
    }

    for (int i = 1; i <= m; i++) {
        update(1, 1, X, 1, b[i], -1);
    }

    int q;
    cin >> q;

    for (int iter = 0; iter < q; iter++) {
        int t, i, x;
        cin >> t >> i >> x;
        if (t == 1) {
            update(1, 1, X, 1, a[i], -1);
            int y = a[i];
            a[i] = x;
            update(1, 1, X, 1, a[i], +1);
            put(1, 1, X, y, -1);
            put(1, 1, X, x, +1);
        } else {
            update(1, 1, X, 1, b[i], +1);
            b[i] = x;
            update(1, 1, X, 1, b[i], -1);
        }
        cout << query(1, 1, X) << "\n";
    }

    return 0;
}