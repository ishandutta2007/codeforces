#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

struct RangeTree {
    int n = 0; // [1, n]
    vector<int> t;

    RangeTree(int nn, const vector<int>& a) {
        n = nn;
        int sz = 1;
        while (sz < n)
            sz <<= 1;
        sz <<= 1;
        t.resize(sz);
        build(1, 1, n, a);
    }

    void merge(int v) {
        t[v] = gcd(t[v << 1], t[v << 1 | 1]);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            merge(v);
        }
    }

    void update(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            t[v] = value;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm)
                update(v << 1, tl, tm, pos, value);
            else
                update(v << 1 | 1, tm + 1, tr, pos, value);
            merge(v);
        }
    }

    void update(int pos, int value) {
        update(1, 1, n, pos, value);
    }

    void query(int v, int tl, int tr, int l, int r, int x, int& cnt) {
        if (cnt >= 2 || t[v] % x == 0)
            return;
        if (tl == tr) {
            cnt++;
        } else {
            int tm = (tl + tr) >> 1;
            if (l <= tm)
                query(v << 1, tl, tm, l, r, x, cnt);
            if (r > tm)
                query(v << 1 | 1, tm + 1, tr, l, r, x, cnt);
        }
    }

    bool query(int l, int r, int x) {
        int cnt = 0;
        query(1, 1, n, l, r, x, cnt);
        return cnt < 2;
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    RangeTree rt(n, a);

    int q;
    cin >> q;

    for (int iter = 0; iter < q; iter++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            cout << (rt.query(l, r, x) ? "YES" : "NO") << "\n";
        } else {
            int i, y;
            cin >> i >> y;
            rt.update(i, y);
        }
    }

    return 0;
}