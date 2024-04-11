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

struct Fen {
    int n; // [0, n)
    vector<int> f, a;

    Fen(int nn) {
        n = nn;
        f.resize(n);
        a.resize(n);
    }

    void put(int i) {
        if (a[i])
            return;
        a[i] = 1;
        for (int cur = i; cur < n; cur |= (cur + 1))
            f[cur]++;
    }

    int get(int i) {
        int res = 0;
        for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += f[cur];
        return res;
    }

    int get(int l, int r) {
        if (l > r)
            return 0;
        return get(r) - get(l - 1);
    }
};

struct RangeTree {
    vector<int> pu;
    vector<pii> mx;
    int n; // [1, n]

    RangeTree(int nn, const vector<int>& a) {
        n = nn;
        pu.resize(4 * n);
        mx.resize(4 * n);
        build(1, 1, n, a);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            pu[v] = 0;
            mx[v] = {a[tl], tl};
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            merge(v);
        }
    }

    void inc(int v, int x) {
        pu[v] += x;
        mx[v].first += x;
    }

    void push(int v) {
        if (pu[v]) {
            inc(v << 1, pu[v]);
            inc(v << 1 | 1, pu[v]);
            pu[v] = 0;
        }
    }

    void merge(int v) {
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void add(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            inc(v, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                add(v << 1, tl, tm, l, r, x);
            if (r > tm)
                add(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void add(int l, int r, int x) {
        if (l > r)
            return;
        add(1, 1, n, l, r, x);
    }

    int get() {
        if (mx[1].first == 0)
            return mx[1].second;
        else
            return -1;
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

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] - i;
    }

    vector<tuple<int, int, int>> queries;

    for (int iter = 0; iter < q; iter++) {
        int x, y;
        cin >> x >> y;
        queries.emplace_back(x, y, iter);
//        vector<int> b = a;
//
//        int res = 0;
//        for (int jit = 0; jit < n; jit++) {
//            int pos = n;
//            while (pos > x && b[pos])
//                pos--;
//            if (pos > x) {
//                for (int k = pos; k <= n; k++)
//                    b[k]++;
//                if (pos <= n - y)
//                    res++;
//            } else
//                break;
//        }
//        cout << res << "\n";
    }

    sort(queries.rbegin(), queries.rend());

    Fen fen(n + 1);

    vector<int> res(q);

    for (int i = 1; i <= n; i++)
        if (a[i] > 0)
            a[i] = -inf;

    RangeTree rt(n, a);

    for (auto [x, y, id] : queries) {
        while (1) {
//            int pos = n;
//            while (pos > x && a[pos])
//                pos--;
//            if (pos <= x)
//                break;
//            a[pos] -= inf;
//            for (int k = pos + 1; k <= n; k++)
//                a[k]++;
            int pos = rt.get();
            if (pos <= x)
                break;
            rt.add(pos, pos, -inf);
            rt.add(pos + 1, n, +1);
            fen.put(pos);
        }
        res[id] = fen.get(x + 1, n - y);
    }

    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";

    return 0;
}