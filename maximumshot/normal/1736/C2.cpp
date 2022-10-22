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

struct RMQ {
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pii>> rmq;

    RMQ(const vector<int>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pii>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pii get_min(int l, int r) const {
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> mx, pu;
    vector<ll> sm;

    RangeTree() = default;

    RangeTree(vector<int> a) {
        n = (int) a.size();
        mx.assign(4 * n, -inf);
        pu.assign(4 * n, -1);
        sm.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            mx[v] = a[tl];
            pu[v] = -1;
            sm[v] = a[tl];
        } else {
            int tm = tl + (tr - tl) / 2;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            merge(v);
        }
    }

    void merge(int v) {
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]);
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
    }

    void upd(int v, int tl, int tr, int x) {
        pu[v] = x;
        mx[v] = x;
        sm[v] = 1ll * x * (tr - tl + 1);
    }

    void push(int v, int tl, int tm, int tr) {
        if (pu[v] != -1) {
            upd(v << 1, tl, tm, pu[v]);
            upd(v << 1 | 1, tm + 1, tr, pu[v]);
            pu[v] = -1;
        }
    }

    void set(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            mx[v] = x;
            sm[v] = x;
            pu[v] = -1;
        } else {
            int tm = tl + (tr - tl) / 2;
            push(v, tl, tm, tr);
            if (i <= tm) set(v << 1, tl, tm, i, x);
            else set(v << 1 | 1, tm + 1, tr, i, x);
            merge(v);
        }
    }

    void set(int i, int x) {
        set(1, 0, n - 1, i, x);
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            upd(v, tl, tr, x);
        } else {
            int tm = tl + (tr - tl) / 2;
            push(v, tl, tm, tr);
            if (l <= tm) update(v << 1, tl, tm, l, r, x);
            if (r > tm) update(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void update(int l, int r, int x) {
        update(1, 0, n - 1, l, r, x);
    }

    int descent(int v, int tl, int tr, int from, int lb) {
        if (tl == tr) {
            return mx[v] > lb ? tl : n;
        } else if (from <= tl) {
            if (mx[v] <= lb) return n;
            int tm = tl + (tr - tl) / 2;
            push(v, tl, tm, tr);
            int res = descent(v << 1, tl, tm, from, lb);
            if (res == n) res = descent(v << 1 | 1, tm + 1, tr, from, lb);
            merge(v);
            return res;
        } else {
            int tm = tl + (tr - tl) / 2;
            push(v, tl, tm, tr);
            int res = n;
            if (from <= tm) res = descent(v << 1, tl, tm, from, lb);
            if (res == n) res = descent(v << 1 | 1, tm + 1, tr, from, lb);
            merge(v);
            return res;
        }
    }

    int descent(int from, int lb) {
        return descent(1, 0, n - 1, from, lb);
    }

    ll query() {
        return sm[1];
    }

    int get_max(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return mx[v];
        } else {
            int tm = tl + (tr - tl) / 2;
            push(v, tl, tm, tr);
            int res = -inf;
            if (l <= tm) res = max(res, get_max(v << 1, tl, tm, l, r));
            if (r > tm) res = max(res, get_max(v << 1 | 1, tm + 1, tr, l, r));
            merge(v);
            return res;
        }
    }

    int get_max(int l, int r) {
        if (l > r) return -inf;
        return get_max(1, 0, n - 1, l, r);
    }
};

ll solve_slow(int n, vector<int> a) {
    for (int i = 0; i < n; i++) {
        a[i] = i - a[i] + 1;
        a[i] = -a[i];
    }
    RMQ rmq(a);
    ll res = 0;
    for (int l = 0; l < n; l++) {
//            for (int r = l; r < n; r++) {
//                if (a[r] > l) break;
//                res++;
//            }
        if (-a[l] > l) continue;
        int bl = l, br = n, bm;
        while (br - bl > 1) {
            bm = bl + (br - bl) / 2;
            if (-rmq.get_min(l, bm).first > l) br = bm;
            else bl = bm;
        }
        res += bl - l + 1;
    }
    return res;
}

struct input {
    int n, q;
    vector<int> a;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) cin >> x;
        cin >> q;
        qs.resize(q);
        for (auto& [p, x] : qs) {
            cin >> p >> x;
            p--;
        }
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        cout << q << "\n";
        for (auto [p, x] : qs)
            cout << p + 1 << " " << x << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 10;
        n = rnd() % MAXN + 1;
        q = rnd() % MAXN + 1;
//        q = 1;
        a.resize(n);
        for (auto& x : a) x = rnd() % n + 1;
        qs.resize(q);
        for (auto& [p, x] : qs) {
            p = rnd() % n;
            x = rnd() % n + 1;
        }
    }

    void gen_max_test() {

    }

    output fast() {
        for (int i = 0; i < n; i++) {
            a[i] = max(0, i - a[i] + 1);
        }
        vector<int> f = a;
        for (int i = 1; i < n; i++)
            f[i] = max(f[i], f[i - 1]);
        vector<ll> sumf(f.begin(), f.end());
        for (int i = 1; i < n; i++)
            sumf[i] += sumf[i - 1];
        RangeTree rt_a(a), rt_f(f);
        vector<ll> res;
        vector<ll> sf(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int j = rt_a.descent(i, a[i]);
            sf[i] = 1ll * (j - i) * a[i] + sf[j];
        }
        for (auto [p, x] : qs) {
            int val = max(0, p - x + 1);
            rt_a.set(p, val);
            val = rt_a.get_max(0, p);
            int to = rt_a.descent(p, val);
            ll tmp = 0;
            if (0 < p) tmp += sumf[p - 1];
            tmp += 1ll * (to - p) * val;
            tmp += sf[to];
            tmp = 1ll * n * (n + 1) / 2 - tmp;
            res.push_back(tmp);
            rt_a.set(p, a[p]);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<ll> res;
        for (auto [p, x] : qs) {
            swap(a[p], x);
            ll tmp = solve_slow(n, a);
            res.push_back(tmp);
            swap(a[p], x);
        }
        return output{res};
    }
#endif
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t = 1;
#ifdef DEBUG
    cin >> t;
#endif
    while (t--)
        test_case();
}

#ifdef DEBUG
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
#endif

#ifdef DEBUG
void max_test() {
    input in;
    in.gen_max_test();
    input in_fs = in;
    output fs = in_fs.fast();
    fs.print();
}
#endif

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