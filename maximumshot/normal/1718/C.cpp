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

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

const int MAXX = 2e5 + 5;

int pr[MAXX];

void precalc() {
    fill(pr, pr + MAXX, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < MAXX; p++) {
        if (!pr[p]) continue;
        for (int x = p * p; x < MAXX; x += p)
            pr[x] = 0;
    }
}

struct RT {
    int n = 0; // [0, n)
    vector<ll> t;

    RT() = default;

    RT(const vector<ll>& a) {
        n = (int) a.size();
        t.assign(2 * n, -inf64);
        for (int i = 0; i < n; i++)
            t[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int i, ll x) {
        for (i += n, t[i] += x, i >>= 1; i > 0; i >>= 1)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    ll get(int l, int r) {
        ll mx = -inf64;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) mx = max(mx, t[l++]);
            if (r & 1) mx = max(mx, t[--r]);
        }
        return mx;
    }
};

struct input {
    int n, q;
    vector<int> a;
    vector<pii> qs;

    input() = default;

    void read() {
        cin >> n >> q;
        a.resize(n);
        for (auto& x : a) cin >> x;
        qs.resize(q);
        for (auto& [p, x] : qs)
            cin >> p >> x, p--;
    }

    void print() {
        cout << n << " " << q << "\n";
        for (auto x : a) cout << x << " ";
        cout << "\n";
        for (auto [p, x] : qs)
            cout << p + 1 << " " << x << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 100;
        const int MAXX = inf;
        n = rnd() % MAXN + 2;
        q = rnd() % MAXN;
        a.resize(n);
        for (auto& x : a) x = rnd() % MAXX + 1;
        qs.resize(q);
        for (auto& [p, x] : qs) {
            p = rnd() % n;
            x = rnd() % MAXX + 1;
        }
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> ks;
        for (int p = 2; p < n; p++) {
            if (n % p == 0)
                ks.push_back(p);
        }
        int sz = (int) ks.size();
//        vector<vector<ll>> f(sz);
        vector<RT> rt(sz);
        vector<int> g(sz);
        vector<ll> f(n);
        for (int i = 0; i < sz; i++) {
            int k = ks[i];
            g[i] = gcd(n, k);
            f.assign(g[i], 0);
            for (int j = 0; j < n; j++)
                f[j % g[i]] += a[j];
            rt[i] = RT(f);
        }
        vector<ll> res;
        ll S = 0;
        for (auto x : a) S += x;
        for (int it = -1; it < q; it++) {
            if (it >= 0) {
                auto [p, x] = qs[it];
                ll delta = x - a[p];
                a[p] = x;
                S += delta;
                for (int i = 0; i < sz; i++) {
//                    f[i][p % g[i]] += delta;
                    rt[i].upd(p % g[i], delta);
                }
            }
            ll mx = S;
            for (int i = 0; i < sz; i++) {
//                ll tmp = *max_element(f[i].begin(), f[i].end());
                ll tmp = rt[i].get(0, g[i] - 1);
                tmp *= g[i];
                mx = max(mx, tmp);
            }
//            for (int k : ks) {
//                int A = n / gcd(n, k);
//                for (int s = 0; s < k; s++) {
//                    ll tmp = 0;
//                    for (int j = 0; j < A; j++)
//                        tmp += a[(s + j * k) % n];
//                    tmp *= gcd(n, k);
//                    mx = max(mx, tmp);
//                }
//            }
            res.push_back(mx);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        vector<ll> res;
        for (int it = -1; it < q; it++) {
            if (it >= 0) {
                auto [p, x] = qs[it];
                a[p] = x;
            }
            ll mx = 0;
            for (int s = 0; s < n; s++) {
                for (int k = 1; k < n; k++) {
                    ll tmp = 0;
                    for (int j = 0; j < n; j++) {
                        tmp += a[(s + j * k) % n];
                    }
                    mx = max(mx, tmp);
                }
            }
            res.push_back(mx);
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

void help() {
    const int MAXX = 2e5 + 5;
    vector<int> d(MAXX);
    for (int x = 1; x < MAXX; x++) {
        for (int y = x; y < MAXX; y += x)
            d[y]++;
    }
    cout << *max_element(d.begin(), d.end()) << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    precalc();
    work();
//    test();
//    max_test();

    return 0;
}