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

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> pu, mx;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        clear();
    }

    void clear() {
        pu.assign(4 * n, 0);
        mx.assign(4 * n, 0);
    }

    void inc(int v, int dx) {
        pu[v] += dx;
        mx[v] += dx;
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

    void inc(int v, int tl, int tr, int l, int r, int dx) {
        if (l <= tl && tr <= r) {
            inc(v, dx);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm) inc(v << 1, tl, tm, l, r, dx);
            if (r > tm) inc(v << 1 | 1, tm + 1, tr, l, r, dx);
            merge(v);
        }
    }

    void inc(int l, int r, int dx) {
        if (l > r) return;
        inc(1, 0, n - 1, l, r, dx);
    }

    int get(int v, int tl, int tr, int i) {
        if (tl == tr) {
            return pu[v];
        } else {
            int tm = (tl + tr) >> 1, res = 0;
            push(v);
            if (i <= tm) res = get(v << 1, tl, tm, i);
            else res = get(v << 1 | 1, tm + 1, tr, i);
            merge(v);
            return res;
        }
    }

    int get(int i) {
        return get(1, 0, n - 1, i);
    }

    int descent(int v, int tl, int tr) {
        if (tl == tr) {
            return tl;
        } else {
            int tm = (tl + tr) >> 1, res;
            push(v);
            if (mx[v << 1 | 1] > 0) res = descent(v << 1 | 1, tm + 1, tr);
            else res = descent(v << 1, tl, tm);
            merge(v);
            return res;
        }
    }

    int descent() {
        return descent(1, 0, n - 1);
    }
};

struct Processor {
    int n = 0; // [0, n)
    vector<int> a;
    Processor() = default;
    Processor(int nn) {
        n = nn;
        a.assign(n, 0);
    }
    void increase(int i, int x) {
        for (int cur = i; cur < n; cur |= (cur + 1))
            a[cur] += x;
    }
    void inc(int l, int r, int x) {
        increase(l, x);
        increase(r + 1, -x);
    }
    int descent() {
        int pos = 0;
        int bnd = 0;
        for (int pw = 1 << 19; pw > 0; pw >>= 1) {
            if (pos + pw <= n && a[pos + pw - 1] > bnd) {
                bnd -= a[pos + pw - 1];
                pos += pw;
            }
        }
        return pos;
    }
    int get(int i) {
        int res = 0;
        for (int cur = i; cur >= 0; cur = (cur & (cur + 1)) - 1)
            res += a[cur];
        return res;
    }
    void clear() {
        a.assign(n, 0);
    }
};

struct output {
    int res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct pt {
    int x = 0;
    int y = 0;
    int c = 0;
};

struct input {
    int n;
    vector<pt> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& p : a) {
            cin >> p.x >> p.y >> p.c;
            p.c--;
        }
    }

    void print() {
        cout << n << "\n";
        for (auto p : a)
            cout << p.x << " " << p.y << " " << p.c + 1 << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int N = 20;
        const int X = 100;
        set<pii> used;
        n = rnd() % (N / 3) + 1;
        n *= 3;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            a[i].c = i / (n / 3);
            while (1) {
                a[i].x = rnd() % X;
                a[i].y = rnd() % X;
                if (!used.count({a[i].x, a[i].y})) {
                    used.insert({a[i].x, a[i].y});
                    break;
                }
            }
        }
        shuffle(a.begin(), a.end(), rnd);
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> crd = {-inf - 10, +inf + 10};
        for (auto p : a) {
            crd.push_back(p.x);
            crd.push_back(p.y);
        }
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        int sz = (int) crd.size();
        for (auto& p : a) {
            p.x = lower_bound(crd.begin(), crd.end(), p.x) - crd.begin();
            p.y = lower_bound(crd.begin(), crd.end(), p.y) - crd.begin();
        }
        vector<int> perm_c = {0, 1, 2}, rev_perm_c(3);
        int res = 0;
        vector<vector<int>> cnt(sz + 1, vector<int>(3));
        Processor rt(sz), rt1(sz);
        do {
            for (int j = 0; j < 3; j++)
                rev_perm_c[perm_c[j]] = j;
            for (auto& p : a) p.c = perm_c[p.c];
            {
                for (int it = 0; it < 2; it++) {
                    sort(a.begin(), a.end(), [&](const pt& p1, const pt& p2) {
                        return p1.x < p2.x;
                    });
                    for (int j = 0, i = 0; i < sz; i++) {
                        cnt[i + 1] = cnt[i];
                        while (j < n && a[j].x <= i) cnt[i + 1][a[j++].c]++;
                    }
                    for (int bm = 0, r = 0; r < sz; r++) {
                        int c2 = cnt[sz][2] - cnt[r + 1][2];
                        while (bm < r) {
                            int c1 = cnt[r + 1][1] - cnt[bm + 1][1];
                            int c0 = cnt[bm + 1][0];
                            if (c1 > c0) bm++;
                            else break;
                        }
                        for (int l = max(0, bm - 2); l <= min(r - 1, bm + 2); l++) {
                            int c1 = cnt[r + 1][1] - cnt[l + 1][1];
                            int c0 = cnt[l + 1][0];
                            res = max(res, 3 * min({c0, c1, c2}));
                        }
                    }
                    for (auto& p : a)
                        swap(p.x, p.y);
                }
            }
            {
                for (int it = 0; it < 4; it++) {
                    sort(a.begin(), a.end(), [&](const pt& p1, const pt& p2) {
                        return p1.x < p2.x;
                    });
                    int c2 = n / 3;
                    int C0 = 0, C1 = 0;
                    rt.clear();
                    rt1.clear();
                    for (int i = 0, x = 0; x < sz; x++) {
                        while (i < n && a[i].x <= x) {
                            if (a[i].c == 2) c2--;
                            else if (a[i].c == 1) {
                                C1++;
                                rt.inc(a[i].y + 1, sz - 1, -1);
                                rt1.inc(a[i].y + 1, sz - 1, +1);
                            } else { // a[i].c == 0
                                C0++;
                                rt.inc(0, a[i].y, +1);
                            }
                            i++;
                        }
                        int y0 = rt.descent();
                        for (int y = max(0, y0 - 2); y <= min(sz - 1, y0 + 2); y++) {
                            int diff = rt.get(y);
                            int c1 = rt1.get(y);
                            int c0 = diff + c1;
                            res = max(res, 3 * min({c0, c1, c2}));
                        }
                    }
                    for (auto& p : a) {
                        swap(p.x, p.y);
                        p.x = sz - 1 - p.x;
                    }
                }
            }
            for (auto& p : a) p.c = rev_perm_c[p.c];
        } while (next_permutation(perm_c.begin(), perm_c.end()));
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        int res = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int cnt[3] = {0, 0, 0};
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) cnt[a[i].c]++;
            }
            if (cnt[0] != cnt[1] || cnt[0] != cnt[2]) continue;
            pt ld[3], ru[3];
            for (int j = 0; j < 3; j++) {
                ld[j].x = inf + 10;
                ld[j].y = inf + 10;

                ru[j].x = -inf - 10;
                ru[j].y = -inf - 10;
            }
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) {
                    auto p = a[i];
                    ld[p.c].x = min(ld[p.c].x, p.x);
                    ld[p.c].y = min(ld[p.c].y, p.y);
                    ru[p.c].x = max(ru[p.c].x, p.x);
                    ru[p.c].y = max(ru[p.c].y, p.y);
                }
            }
            int ok = 1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < i; j++) {
                    pair<pt, pt> rec1 = {ld[i], ru[i]};
                    pair<pt, pt> rec2 = {ld[j], ru[j]};
                    int lx = max(rec1.first.x, rec2.first.x);
                    int rx = min(rec1.second.x, rec2.second.x);
                    int ly = max(rec1.first.y, rec2.first.y);
                    int ry = min(rec1.second.y, rec2.second.y);
                    if (lx <= rx && ly <= ry) ok = 0;
                }
            }
            if (ok) res = max(res, int(__builtin_popcount(mask)));
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
    // test();
//    max_test();

    return 0;
}