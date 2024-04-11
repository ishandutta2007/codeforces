#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    vector<ll> res;

    void print() {
        for (auto x : res)
            cout << x << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> mn, mx, pu;
    vector<ll> sm;

    RangeTree() = default;

    RangeTree(const vector<int>& a) {
        n = (int) a.size();
        mn.assign(4 * n, inf + 10);
        mx.assign(4 * n, -inf - 10);
        pu.assign(4 * n, -1);
        sm.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void upd(int v, int x, int len) {
        mn[v] = x;
        mx[v] = x;
        sm[v] = 1ll * len * mn[v];
        pu[v] = mn[v];
    }

    void push(int v, int tl, int tm, int tr) {
        if (pu[v] != -1) {
            upd(v << 1, pu[v], tm - tl + 1);
            upd(v << 1 | 1, pu[v], tr - tm);
            pu[v] = -1;
        }
    }

    void merge(int v) {
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
        mn[v] = min(mn[v << 1], mn[v << 1 | 1]);
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            mn[v] = mx[v] = sm[v] = a[tl];
            pu[v] = -1;
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            merge(v);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (mx[v] < x)
            return;
        if (l <= tl && tr <= r && mn[v] == mx[v]) {
            upd(v, mn[v] % x, tr - tl + 1);
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
        update(1, 0, n - 1, l, r, x);
    }

    void put(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            mn[v] = mx[v] = sm[v] = x;
            pu[v] = -1;
        } else {
            int tm = (tl + tr) >> 1;
            push(v, tl, tm, tr);
            if (i <= tm)
                put(v << 1, tl, tm, i, x);
            else
                put(v << 1 | 1, tm + 1, tr, i, x);
            merge(v);
        }
    }

    void put(int i, int x) {
        put(1, 0, n - 1, i, x);
    }

    ll get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return sm[v];
        } else {
            int tm = (tl + tr) >> 1;
            ll res = 0;
            push(v, tl, tm, tr);
            if (l <= tm)
                res += get(v << 1, tl, tm, l, r);
            if (r > tm)
                res += get(v << 1 | 1, tm + 1, tr, l, r);
            merge(v);
            return res;
        }
    }

    ll get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
};

struct input {
    int n, m;
    vector<int> a;

    struct Query {
        int t, l, r, k, x;
    };

    vector<Query> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
        qs.resize(m);
        for (auto& q : qs) {
            cin >> q.t;
            if (q.t == 1) {
                cin >> q.l >> q.r;
                q.l--, q.r--;
            } else if (q.t == 2) {
                cin >> q.l >> q.r >> q.x;
                q.l--, q.r--;
            } else {
                cin >> q.k >> q.x;
                q.k--;
            }
        }
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        for (auto q : qs) {
            cout << q.t << " ";
            if (q.t == 1) {
                cout << q.l + 1 << " " << q.r + 1 << "\n";
            } else if (q.t == 2) {
                cout << q.l + 1 << " " << q.r + 1 << " " << q.x << "\n";
            } else {
                cout << q.k + 1 << " " << q.x << "\n";
            }
        }
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 50;
        const int MAXX = 50;
        n = rnd() % MAXN + 1;
        m = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX + 1;
        qs.resize(m);
        for (auto& q : qs) {
            q.t = rnd() % 3 + 1;
            if (q.t == 1) {
                q.r = rnd() % n;
                q.l = rnd() % (q.r + 1);
            } else if (q.t == 2) {
                q.r = rnd() % n;
                q.l = rnd() % (q.r + 1);
                q.x = rnd() % MAXX + 1;
            } else {
                q.k = rnd() % n;
                q.x = rnd() % MAXX + 1;
            }
        }
    }

    void gen_max_test() {

    }

    output fast() {
        vector<ll> res;
        RangeTree rt(a);
        for (auto q : qs) {
            if (q.t == 1) {
                res.push_back(rt.get(q.l, q.r));
            } else if (q.t == 2) {
                rt.update(q.l, q.r, q.x);
            } else if (q.t == 3) {
                rt.put(q.k, q.x);
            }
        }
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        vector<ll> res;
        for (auto q : qs) {
            if (q.t == 1) {
                ll s = 0;
                for (int i = q.l; i <= q.r; i++)
                    s += a[i];
                res.push_back(s);
            } else if (q.t == 2) {
                for (int i = q.l; i <= q.r; i++)
                    a[i] %= q.x;
            } else {
                a[q.k] = q.x;
            }
        }
        return output{res};
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
    while (t--)
        test_case();
}

void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}

void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();
//    max_test();

    return 0;
}