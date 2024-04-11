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
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> sm;

    RangeTree() = default;

    RangeTree(const vector<int>& f) {
        n = (int) f.size();
        sm.resize(4 * n, 0);
        build(1, 0, n - 1, f);
    }

    void merge(int v) {
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
    }

    void build(int v, int tl, int tr, const vector<int>& f) {
        if (tl == tr) {
            sm[v] = f[tl];
        } else {
            int tm = tl + (tr - tl) / 2;
            build(v << 1, tl, tm, f);
            build(v << 1 | 1, tm + 1, tr, f);
            merge(v);
        }
    }

    void upd(int v, int tl, int tr, int i, int dx) {
        if (tl == tr) {
            sm[v] += dx;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (i <= tm) upd(v << 1, tl, tm, i, dx);
            else upd(v << 1 | 1, tm + 1, tr, i, dx);
            merge(v);
        }
    }

    void upd(int i, int dx) {
        upd(1, 0, n - 1, i, dx);
    }

    int get(int v, int tl, int tr, int k) {
        if (tl == tr) {
            return tl;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (sm[v << 1] >= k) return get(v << 1, tl, tm, k);
            else return get(v << 1 | 1, tm + 1, tr, k - sm[v << 1]);
        }
    }

    int get(int k) {
        return get(1, 0, n - 1, k);
    }
};

struct input {
    int n, k;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n >> k;
        a.resize(n);
        for (auto& x : a) cin >> x;
    }

    void print() {
        cout << n << " " << k << "\n";
        for (auto x : a) cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        const int MAXX = 10;
        n = rnd() % MAXN + 2;
        k = rnd() % n + 1;
        a.resize(n);
        for (auto& x : a) x = rnd() % MAXX + 1;
    }

    void gen_max_test() {

    }

    output fast() {
        if (k == n) return output{inf};
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&](int i, int j) {
            return a[i] < a[j];
        });
        multiset<int> Q(a.begin(), a.end());
        vector<int> pref(n), suff(n);
        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], min(a[i], a[i - 1]));
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], min(a[i], a[i + 1]));
        }
        vector<int> crd = a;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        int sz = (int) crd.size();
        vector<int> f(sz);
        for (auto x : a) {
            x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
            f[x]++;
        }
        RangeTree rt(f);
        int res = 0;
        { // try 0
            int d = 0;
            for (int i = 0; i + 1 < n; i++)
                d = max(d, min(a[i], a[i + 1]));
            res = min(d, 2 * crd[rt.get(k + 1)]);
        }
        { // try 1
            for (int i = 0; i < n; i++) {
                int pos = lower_bound(crd.begin(), crd.end(), a[i]) - crd.begin();
                rt.upd(pos, -1);
                int d = 0;
                if (i + 1 < n) d = max(d, a[i + 1]);
                if (i > 0) d = max(d, a[i - 1]);
                int pos_min = rt.get(k);
                d = min(d, 2 * crd[pos_min]);
                res = max(res, d);
                rt.upd(pos, +1);
            }
        }
        if (k >= 2) { // try 2
            for (int i = 0; i + 1 < n; i++) {
                int pos_i = lower_bound(crd.begin(), crd.end(), a[i]) - crd.begin();
                int pos_ni = lower_bound(crd.begin(), crd.end(), a[i + 1]) - crd.begin();
                rt.upd(pos_i, -1);
                rt.upd(pos_ni, -1);
                int d = inf;
                d = min(d, 2 * crd[rt.get(k - 1)]);
                res = max(res, d);
                rt.upd(pos_i, +1);
                rt.upd(pos_ni, +1);
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        int res = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) > k) continue;
            vector<int> b = a;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) b[i] = inf;
            }
            vector<vector<int>> d(n, vector<int>(n, inf));
            for (int i = 0; i < n; i++) d[i][i] = 0;
            for (int u = 0; u < n; u++) {
                for (int v = u + 1; v < n; v++) {
                    d[u][v] = *min_element(b.begin() + u, b.begin() + v + 1);
                    d[v][u] = d[u][v];
                }
            }
            for (int w = 0; w < n; w++) {
                for (int u = 0; u < n; u++) {
                    for (int v = 0; v < n; v++) {
                        d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
                    }
                }
            }
            int diam = 0;
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    diam = max(diam, d[u][v]);
                }
            }
            res = max(res, diam);
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
    int t;
    cin >> t;
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