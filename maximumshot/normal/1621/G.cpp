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

const int mod = inf + 7;

inline int sum_(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int mul_(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int sub_(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void inc_(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void dec_(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int binpow_(int x, int pw) {
    if (x == 0)
        return 0;
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = mul_(res, tmp);
        }
        tmp = mul_(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int div_(int a, int b) {
    return mul_(a, binpow_(b, mod - 2));
}

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
    vector<int> t;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.assign(2 * n, 0);
    }

    void put(int i, int x) {
        for (i += n, inc_(t[i], x), i >>= 1; i > 0; i >>= 1)
            t[i] = sum_(t[i << 1], t[i << 1 | 1]);
    }

    int get(int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) inc_(res, t[l++]);
            if (r & 1) inc_(res, t[--r]);
        }
        return res;
    }
};

struct input {
    int n, sz;
    vector<int> a, crd;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 3;
        const int MAXX = 5;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX;
    }

    void gen_max_test() {

    }

    output fast() {
        crd = a;
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        sz = (int) crd.size();
        for (auto& x : a)
            x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();

        vector<int> cn(n), sm(n);
        RangeTree rt_cn(sz), rt_sm(sz);
        for (int i = 0; i < n; i++) {
            cn[i] = 1;
            int CN = rt_cn.get(0, a[i] - 1);
            int SM = sum_(rt_sm.get(0, a[i] - 1), CN);
            inc_(cn[i], CN);
            inc_(sm[i], SM);
            rt_cn.put(a[i], cn[i]);
            rt_sm.put(a[i], sm[i]);
        }

        int res = 0;
        vector<int> nxt(n, -1), mx(n + 1, -inf);
        for (int sf = -1, i = n - 1; i >= 0; i--) {
            if (sf != -1 && a[sf] > a[i]) inc_(res, cn[i]);
            else if (sf == -1 || a[sf] < a[i]) sf = i;
            inc_(res, sm[i]);
            mx[i] = a[sf];
        }

        for (int i = 0; i < n; i++) {
            if (a[i] >= mx[i]) {
                nxt[i] = -1;
                continue;
            }
            int bl = i, br = n, bm;
            while (br - bl > 1) {
                bm = (bl + br) >> 1;
                if (a[i] < mx[bm]) bl = bm;
                else br = bm;
            }
            nxt[i] = bl;
        }

        vector<int> f(n);
//        for (int i = n - 1; i >= 0; i--) {
//            if (nxt[i] == -1)
//                continue;
//            f[i] = 1;
//            for (int j = i + 1; j < n; j++) {
//                if (a[i] < a[j] && a[j] < a[nxt[i]])
//                    inc_(f[i], f[j]);
//            }
//            for (int j = nxt[i]; j < n; j++) {
//                if (a[i] < a[j] && a[j] < a[nxt[i]])
//                    dec_(f[i], f[j]);
//            }
//            dec_(res, mul_(f[i], cn[i]));
//        }

        vector<vector<pii>> upd(n);
        for (int i = 0; i < n; i++) {
            if (nxt[i] == -1)
                continue;
            f[i] = 1;
            upd[i + 1].emplace_back(i, +1);
            upd[nxt[i]].emplace_back(i, mod - 1);
        }

        RangeTree rt(sz);
        for (int i = n - 1; i >= 0; i--) {
            rt.put(a[i], f[i]);
            for (auto [j, t] : upd[i]) {
                int l = a[j] + 1, r = a[nxt[j]] - 1;
                if (l > r)
                    continue;
                inc_(f[j], mul_(t, rt.get(l, r)));
            }
            if (nxt[i] != -1)
                dec_(res, mul_(f[i], cn[i]));
        }

        return output{res};
    }

    output slow() {
        int res = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            vector<int> in;
            int ok = 1;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) {
                    if (!in.empty())
                        ok &= a[in.back()] < a[i];
                    in.push_back(i);
                }
            }
            if (!ok)
                continue;
            int mx = -inf;
            for (int j = n - 1; j > in.back(); j--)
                mx = max(mx, a[j]);
            for (int i : in) {
                if (a[i] < mx)
                    inc_(res, 1);
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
    int t;
    cin >> t;
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