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

struct RangeTree {
    int n;
    vector<ll> mn, sm, pu;

    RangeTree(int n, const vector<int>& a): n(n) {
        mn.resize(4 * n, inf64);
        sm.resize(4 * n);
        pu.resize(4 * n);
        build(1, 1, n, a);
    }

    void put(int v, int tl, int tr, int x) {
        mn[v] = x;
        sm[v] = 1ll * (tr - tl + 1) * x;
        pu[v] = x;
    }

    void push(int v, int tl, int tm, int tr) {
        if (pu[v]) {
            put(v << 1, tl, tm, pu[v]);
            put(v << 1 | 1, tm + 1, tr, pu[v]);
            pu[v] = 0;
        }
    }

    void merge(int v) {
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            put(v, tl, tr, a[tl]);
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            merge(v);
        }
    }

    int next_less(int v, int tl, int tr, int start, int value) {
        if (tr < start || mn[v] > value)
            return inf;
        if (tl == tr) {
            return mn[v] > value ? inf : tl;
        } else {
            int tm = (tl + tr) >> 1;
            push(v, tl, tm, tr);
            int res = inf;
            if (res == inf)
                res = next_less(v << 1, tl, tm, start, value);
            if (res == inf)
                res = next_less(v << 1 | 1, tm + 1, tr, start, value);
            merge(v);
            return res;
        }
    }

    int next_less(int start, int value) {
        return next_less(1, 1, n, start, value);
    }

    pair<ll, int> jump(int v, int tl, int tr, int start, ll can) {
        if (tr < start) {
            return {can, -1};
        }
        if (start <= tl && sm[v] <= can)
            return {can - sm[v], tr};
        if (tl == tr) {
            if (mn[v] > can) {
                return {can, -1};
            } else {
                return {can - mn[v], tl};
            }
        } else {
            int tm = (tl + tr) >> 1, res = -1;
            push(v, tl, tm, tr);
            if (start <= tm) {
                auto [rem, tmp] = jump(v << 1, tl, tm, start, can);
                can = rem;
                res = tmp;
                if (res == tm) {
                    auto [_rem, _tmp] = jump(v << 1 | 1, tm + 1, tr, start, can);
                    if (_tmp != -1) {
                        res = _tmp;
                        can = _rem;
                    }
                }
            } else {
                auto [rem, tmp] = jump(v << 1 | 1, tm + 1, tr, start, can);
                res = tmp;
                can = rem;
            }
            merge(v);
            return {can, res};
        }
    }

    pair<ll, int> jump(int start, ll can) {
        return jump(1, 1, n, start, can);
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            put(v, tl, tr, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v, tl, tm, tr);
            if (l <= tm)
                update(v << 1, tl, tm, l, r, x);
            if (r > tm)
                update(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    RangeTree rt(n, a);

    for (int iter = 0; iter < q; iter++) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            int j = rt.next_less(1, y);
            if (j <= x)
                rt.update(j, x, y);
        } else {
            int res = 0;
            int start = x;
            int can = y;
            while (start <= n) {
                int i = rt.next_less(start, can);
                if (i > n)
                    break;
                auto [rem, j] = rt.jump(i, can);
                can = rem;
                res += j - i + 1;
                start = j + 1;
            }
            cout << res << "\n";
        }
    }

    return 0;
}