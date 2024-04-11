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
    ll res;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<ll> t;

    RangeTree() = default;

    RangeTree(int nn) {
        n = nn;
        t.resize(2 * n, -inf64);
    }

    RangeTree(const vector<ll>& ar) {
        n = (int) ar.size();
        t.resize(2 * n, -inf64);
        for (int i = 0; i < n; i++)
            t[i + n] = ar[i];
        for (int i = n - 1; i >= 0; i--)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    void set(int i, ll x) {
        for (i += n, t[i] = max(t[i], x), i >>= 1; i > 0; i >>= 1)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    ll get(int l, int r) {
        ll res = -inf64;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

struct RT {
    int n = 0; // [0, n)
    vector<ll> L, R;

    struct Node {
        ll pr = -inf64;
        ll sf = -inf64;
        ll sm = -inf64;
    };

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.pr = max(l.pr, r.pr);
        res.sf = max(l.sf, r.sf);
        res.sm = max({l.sm, r.sm, l.pr + r.sf});
        return res;
    }

    vector<Node> t;

    RT() = default;

    RT(const vector<ll>& L_, const vector<ll>& R_) {
        L = L_;
        R = R_;
        n = (int) L.size();
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = {L[tl], R[tl], -inf64};
        } else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm);
            build(v << 1 | 1, tm + 1, tr);
            t[v] = merge(t[v << 1], t[v << 1 | 1]);
        }
    }

    Node get(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) {
            return t[v];
        } else {
            int tm = (tl + tr) >> 1;
            Node res;
            if (l <= tm)
                res = merge(res, get(v << 1, tl, tm, l, r));
            if (r > tm)
                res = merge(res, get(v << 1 | 1, tm + 1, tr, l, r));
            return res;
        }
    }

    ll get(int l, int r) {
        Node res = get(1, 0, n - 1, l, r);
        return res.sm;
    }
};

struct input {
    int n, q;
    vector<int> a[3];
    vector<tuple<int, int, int>> segs;

    input() = default;

    void read() {
        cin >> n >> q;
        for (int i = 0; i < 3; i++) {
            a[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        segs.resize(q);
        for (auto& [l, r, k] : segs)
            cin >> l >> r >> k, l--, r--;
    }

    void print() {
        cout << n << " " << q << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << "\n";
        }
        for (auto [l, r, k] : segs)
            cout << l + 1 << " " << r + 1 << " " << k << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        const int MAXX = 3;
        n = rnd() % MAXN + 1;
        for (int i = 0; i < 3; i++) {
            a[i].resize(n);
            for (int j = 0; j < n; j++) {
                a[i][j] = rnd() % (2 * MAXX + 1) - MAXX;
            }
        }
        q = rnd() % MAXN + 1;
//        q = 1;
        segs.resize(q);
        for (auto& [l, r, k] : segs) {
            r = rnd() % n;
            l = rnd() % (r + 1);
            k = rnd() % MAXX + 1;
        }
    }

    void gen_max_test() {

    }

    ll solve(vector<ll> L, vector<ll> R) {
        ll res = -inf64;
        RT rt(L, R);
        for (int i = 0; i < q; i++) {
            auto [l, r, k] = segs[i];
            res = max(res, rt.get(l, r) - k);
//            for (int j1 = l; j1 <= r; j1++) {
//                for (int j2 = j1 + 1; j2 <= r; j2++) {
//                    res = max(res, L[j1] + R[j2] - k);
//                }
//            }
        }
        return res;
    }

    output fast() {
        vector<ll> A[3];
        for (int i = 0; i < 3; i++) {
            A[i].resize(n);
            for (int j = 0; j < n; j++) {
                A[i][j] = (j > 0 ? A[i][j - 1] : 0) + a[i][j];
            }
        }
        sort(segs.begin(), segs.end(), [&](const auto& s1, const auto& s2) {
            return get<1>(s1) < get<1>(s2); // sort by r
        });
        vector<ll> dp(q, -inf64);
        vector<ll> f(n), g(n);
        for (int j = 0; j < n; j++) {
            f[j] = A[0][j] - (j > 0 ? A[1][j - 1] : 0);
            g[j] = A[1][j] - (j > 0 ? A[2][j - 1] : 0);
        }
        RangeTree rt_f(f), rt_g(g), rt(q);
        for (int i = 0; i < q; i++) {
            auto [l, r, k] = segs[i];
            dp[i] = max(dp[i], rt_f.get(l, r));
            dp[i] += A[1][r] - k;
            ll mx = -inf64;
            if (i > 0 && get<1>(segs[i - 1]) >= l - 1) {
                int bl = -1, br = i - 1, bm;
                while (br - bl > 1) {
                    bm = bl + (br - bl) / 2;
                    if (get<1>(segs[bm]) >= l - 1) br = bm;
                    else bl = bm;
                }
                mx = rt.get(br, i - 1);
                mx += A[1][r] - k;
                dp[i] = max(dp[i], mx);
            }
            rt.set(i, dp[i] - A[1][r]);
        }
        ll res = -inf64;
        vector<ll> L(n, -inf64), R(n), ar(n);
        for (int i = 0; i < n; i++) {
            L[i] = A[0][i] + a[1][i] - A[1][i];
            R[i] = A[1][i] + A[2][n - 1] - (i > 0 ? A[2][i - 1] : 0);
            ar[i] = A[0][i] + a[1][i] + A[2][n - 1] - (i > 0 ? A[2][i - 1] : 0);
        }
        RangeTree rt_ar(ar);
        for (int i = 0; i < q; i++) {
            auto [l, r, k] = segs[i];
            res = max(res, rt_ar.get(l, r) - k);
        }
        res = max(res, solve(L, R));
        L.assign(n, -inf64);
        for (int i = 0; i < q; i++) {
            auto [l, r, k] = segs[i];
            L[r] = max(L[r], dp[i]);
        }
        for (int i = 0; i < n; i++) {
            L[i] = L[i] - A[1][i] + A[2][n - 1];
            R[i] = A[1][i] - (i > 0 ? A[2][i - 1] : 0);
        }
        for (auto& [l, r, k] : segs)
            l = max(0, l - 1);
        res = max(res, solve(L, R));
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        ll res = -inf64;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                ll tmp = 0;
                for (int j = 0; j <= l; j++)
                    tmp += a[0][j];
                for (int j = l; j <= r; j++)
                    tmp += a[1][j];
                for (int j = r; j < n; j++)
                    tmp += a[2][j];
                for (int mask = 1; mask < (1 << q); mask++) {
                    vector<int> used(n);
                    ll cost = tmp;
                    for (int i = 0; i < q; i++) {
                        if ((1 << i) & mask) {
                            auto [ql, qr, k] = segs[i];
                            cost -= k;
                            for (int j = ql; j <= qr; j++)
                                used[j] = 1;
                        }
                    }
                    int ok = 1;
                    for (int j = l; j <= r; j++)
                        ok &= used[j];
                    if (ok)
                        res = max(res, cost);
                }
            }
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
//    test();
//    max_test();

    return 0;
}