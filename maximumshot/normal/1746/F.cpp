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
    vector<int> res;

    void print() {
        for (auto x : res)
            cout << (x ? "YES" : "NO") << "\n";
    }

    bool operator == (const output& o) const {
        return res == o.res;
    }
};

struct RangeTree {
    int n = 0; // [0, n)
    vector<ll> t;

    RangeTree() = default;

    RangeTree(const vector<int>& a) {
        n = (int) a.size();
        t.assign(2 * n, 0);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void set(int i, int x) {
        for (i += n, t[i] = x, i >>= 1; i > 0; i >>= 1)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    ll get_sum(int l, int r) {
        ll res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};

struct input {
    int n, m;
    vector<int> a;

    struct Query {
        int type;
        int i, x;
        int l, r, k;

        void print() {
            cout << type << " ";
            if (type == 1) {
                cout << i + 1 << " " << x << "\n";
            } else{
                cout << l + 1 << " " << r + 1 << " " << k << "\n";
            }
        }

        void read() {
            cin >> type;
            if (type == 1) {
                cin >> i >> x;
                i--;
            } else {
                cin >> l >> r >> k;
                l--, r--;
            }
        }

        void gen(mt19937& rnd, int MAXX, int N) {
            type = rnd() % MAXX + 1;
            if (type == 1) {
                i = rnd() % N;
                x = rnd() % MAXX + 1;
            } else {
                r = rnd() % N;
                l = rnd() % (r + 1);
                k = rnd() % N + 1;
            }
        }
    };

    vector<Query> qs;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        for (auto& x : a)
            cin >> x;
        qs.resize(m);
        for (auto& q : qs)
            q.read();
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto x : a)
            cout << x + 1 << " ";
        cout << "\n";
        for (auto q : qs)
            q.print();
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        const int MAXX = 10;
        n = rnd() % MAXN + 1;
        m = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % MAXX + 1;
        qs.resize(m);
        for (auto& q : qs)
            q.gen(rnd, MAXX, n);
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> crd = a;
        for (auto q : qs) {
            if (q.type == 1)
                crd.push_back(q.x);
        }
        sort(crd.begin(), crd.end());
        crd.erase(unique(crd.begin(), crd.end()), crd.end());
        int sz = (int) crd.size();
        auto F = [&](int x) -> int {
            return lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        };
        for (auto& x : a)
            x = F(x);
        for (auto& q : qs) {
            if (q.type == 1)
                q.x = F(q.x);
        }
        int ITERS = 30;
        vector<vector<int>> f(ITERS, vector<int>(sz));
        static mt19937 gen(100);
        for (int j = 0; j < ITERS; j++) {
            for (int i = 0; i < sz; i++) {
                f[j][i] = gen() % inf;
            }
        }
        vector<RangeTree> rt(ITERS);
        for (int j = 0; j < ITERS; j++) {
            vector<int> ar(n);
            for (int i = 0; i < n; i++)
                ar[i] = f[j][a[i]];
            rt[j] = RangeTree(ar);
        }
        vector<int> res;
        res.reserve(m);
        for (auto q : qs) {
            if (q.type == 1) {
                for (int j = 0; j < ITERS; j++) {
                    rt[j].set(q.i, f[j][q.x]);
                }
            } else {
                int ok = 1;
                for (int j = 0; j < ITERS; j++) {
                    ll tmp = rt[j].get_sum(q.l, q.r);

                    ok &= tmp % q.k == 0;
                    if (!ok) break;
                }
                res.push_back(ok);
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<int> res;
        res.reserve(m);
        for (auto q : qs) {
            if (q.type == 1) {
                a[q.i] = q.x;
                continue;
            }
            map<int, int> cnt;
            for (int i = q.l; i <= q.r; i++) {
                cnt[a[i]]++;
            }
            int ok = 1;
            for (auto [k, v] : cnt)
                ok &= v % q.k == 0;
            res.push_back(ok);
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