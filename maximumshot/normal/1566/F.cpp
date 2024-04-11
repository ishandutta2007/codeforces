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
//#ifndef DEBUG
//        assert(false);
//#endif
        n = nn;
        t.assign(2 * n, inf64);
    }

    void set(int i, ll x) {
//        t[i] = x;
        for (i += n, t[i] = x, i >>= 1; i > 0; i >>= 1)
            t[i] = min(t[i << 1], t[i << 1 | 1]);
    }

    ll get(int l, int r) {
        if (l > r) return inf64;
//        return *min_element(t.begin() + l, t.begin() + r + 1);
        ll res = inf64;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};

ll solve_block_fast(vector<int> a, vector<pii> b) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int n = (int) a.size();
    int m = (int) b.size();
    vector<pii> pts;
    for (int i = 0; i < n; i++) {
        pts.emplace_back(a[i], i);
    }
    for (int i = 0; i < m; i++) {
        auto [l, r] = b[i];
        pts.emplace_back(r, n + i);
    }
    sort(pts.begin(), pts.end());
    int sz = (int) pts.size();
    vector<int> le(sz, -1);
    for (int i = 0; i < sz; i++) {
        if (pts[i].second < n) le[i] = i;
        else if (i > 0) le[i] = le[i - 1];
    }
    vector<ll> dp(sz, inf64);
    RangeTree rt1(sz), rt2(sz);
    for (int i = 0; i < sz; i++) {
        int j = le[i];
        if (j < 0) continue;
        int k = j > 0 ? le[j - 1] : -1;
        if (i == j) {
            if (i) dp[i] = dp[i - 1];
            else dp[i] = 0;
//            for (int q = max(k + 1, 1); q < i; q++) {
//                dp[i] = min(dp[i], dp[q - 1] + pts[i].first - pts[q].first);
//            }
            dp[i] = min(dp[i], pts[i].first + rt1.get(max(k + 1, 1), i - 1));
            if (k == -1 && 0 < i) {
                dp[i] = min(dp[i], 0ll + pts[i].first - pts[0].first);
            }
        } else {
            int cur_id = pts[i].second - n;
            int R = b[cur_id].first - pts[j].first;
            dp[i] = (j > 0 ? dp[j - 1] : 0) + R;
            assert(R > 0);
            int ql = max(1, k + 1);
            int qr = j - 1, qm;
            if (ql <= qr) {
                int bl = ql, br = qr + 1, bm;
                while (br - bl > 1) {
                    bm = bl + (br - bl) / 2;
                    int x = pts[j].first - pts[bm].first;
                    if (x >= R) bl = bm;
                    else br = bm;
                }
                qm = bl;

                if (ql <= qm) {
                    ll tmp = inf64;
                    tmp = rt1.get(ql, qr);
//                    for (int q = ql; q <= qm; q++)
//                        tmp = min(tmp, dp[q - 1] - pts[q].first);
                    dp[i] = min(dp[i], tmp + pts[j].first + 2ll * R);
                }
                if (qm <= qr) {
                    ll tmp = inf64;
                    tmp = rt2.get(qm, qr);
//                    for (int q = qm; q <= qr; q++)
//                        tmp = min(tmp, dp[q - 1] - 2ll * pts[q].first);
                    dp[i] = min(dp[i], tmp + 2ll * pts[j].first + R);
                }
            }
            if (k == -1 && 0 < j) {
                int x = pts[j].first - pts[0].first;
                dp[i] = min(dp[i], 0ll + x + R + min(x, R));
            }
        }

        rt1.set(i, (i ? dp[i - 1] : 0) - pts[i].first);
        rt2.set(i, (i ? dp[i - 1] : 0) - 2ll * pts[i].first);
    }
#ifdef DEBUG
//    cout << "\n===============\n";
//    for (int i = 0; i < sz; i++) {
//        auto [x, id] = pts[i];
//        cout << x << " ";
//        if (id < n) cout << "p\n";
//        else if ((id - n) % 2 == 0) cout << "l(" << (id - n) / 2 << ")\n";
//        else cout << "r(" << (id - n) / 2 << ")\n";
//    }
#endif
    return dp[sz - 1];
}

struct input {
    int n, m;
    vector<int> a;
    vector<pii> b;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a) cin >> x;
        b.resize(m);
        for (auto& [l, r] : b) cin >> l >> r;
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        for (auto [l, r] : b)
            cout << l << " " << r << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 3;
        const int MAXM = 3;
        const int MAXX = 10;
        n = rnd() % MAXN + 1;
        m = rnd() % MAXM + 1;
        int last = -MAXX - 1;
        a.resize(n);
        for (auto& x : a) {
            x = last + int(rnd() % MAXX) + 1;
            last = x;
        }
        shuffle(a.begin(), a.end(), rnd);
        b.resize(m);
        for (auto& [l, r] : b) {
            l = int(rnd() % (2 * MAXX + 1)) - MAXX;
            r = int(rnd() % (2 * MAXX + 1)) - MAXX;
            if (l > r) swap(l, r);
        }
    }

    void gen_max_test() {

    }

    output fast() {
        { // remove too big segments
            sort(b.begin(), b.end(), [&](auto s1, auto s2) {
                auto [l1, r1] = s1;
                auto [l2, r2] = s2;
                return r1 < r2 || (r1 == r2 && l1 > l2);
            });
            vector<pii> bb;
            int L = -inf - 10;
            for (auto [l, r] : b) {
                if (l <= L) continue;
                L = l;
                bb.emplace_back(l, r);
            }
            swap(b, bb);
            m = (int) b.size();
        }
        { // remove already covered segments
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            int ptr = 0;
            vector<pii> bb;
            for (auto [l, r] : b) {
                while (ptr < n && a[ptr] < l) ptr++;
                if (ptr < n && a[ptr] <= r) continue;
                bb.emplace_back(l, r);
            }
            swap(b, bb);
            m = (int) b.size();
        }
        sort(b.begin(), b.end());
#ifdef DEBUG
        cout << "segments\n";
        for (auto [l, r] : b)
            cout << l << " " << r << "\n";
#endif
        vector<pii> pts;
        for (int i = 0; i < n; i++) {
            pts.emplace_back(a[i], i);
        }
        for (int i = 0; i < m; i++) {
            auto [l, r] = b[i];
            pts.emplace_back(l, n + 2 * i);
            pts.emplace_back(r, n + 2 * i + 1);
        }
        sort(pts.begin(), pts.end());
        ll res = 0;
        for (int i = 0; i < (int) pts.size(); i++) {
            int j = i;
            while (j + 1 < (int) pts.size() && (pts[j].second >= n || pts[j + 1].second >= n)) j++;
            // [i, j]
            vector<int> aa;
            vector<pii> bb;
            for (int q = i; q <= j; q++) {
                auto [x, id] = pts[q];
                if (id < n) aa.push_back(x);
                else {
                    id -= n;
                    id /= 2;
                    bb.push_back(b[id]);
                }
            }
            ll tmp = solve_block_fast(aa, bb);
            res += tmp;
            i = j;
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<ll> dp(1 << m, inf64);
        dp[0] = 0;
        for (auto x : a) {
            for (int mask = (1 << m) - 1; mask > 0; mask--) {
                for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                    int L = x, R = x;
                    for (int j = 0; j < m; j++) {
                        if ((1 << j) & sub) {
                            auto [l, r] = b[j];
                            if (x < l) R = max(R, l);
                            else if (x > r) L = min(L, r);
                        }
                    }
                    dp[mask] = min(dp[mask], dp[mask ^ sub] + R - L + min(x - L, R - x));
                }
            }
        }
        ll res = dp[(1 << m) - 1];
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