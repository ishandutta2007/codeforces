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

struct SQRT {
    int n = 0; // [1, n]
    int k = 0;
    vector<ll> a, A, pref, PREF;

    SQRT() = default;

    SQRT(const vector<ll>& a_) {
        n = (int) a_.size() - 1;
        a = a_;
        k = sqrt(n) + 5;
        A.assign(n / k + 1, 0);

        pref.assign(n + 1, 0);
        PREF.assign(n / k + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (i % k) pref[i] = pref[i - 1] + a[i];
            else pref[i] = a[i];
            PREF[i / k] += a[i];
        }
        for (int i = 1; i < (int) PREF.size(); i++)
            PREF[i] += PREF[i - 1];
    }

    void update(int i, ll x) {
        int b = i / k;
        for (int j = b + 1; j < (int) A.size(); j++)
            A[j] += x;
        int to = min(n, b * k + k - 1), coef = 1;
        ll cur = 0;
        while (i <= to)
            a[i] += x, pref[i] += 1ll * x * coef, coef++, i++, cur += x;
        PREF[b] += cur;
        b++;
        while (b < (int) PREF.size()) {
            int ql = b * k;
            int qr = min(n, b * k + k - 1);
            int len = max(0, qr - ql + 1);
            cur += 1ll * len * x;
            PREF[b] += cur;
            b++;
        }
    }

    ll get(int i) {
        return a[i] + A[i / k];
    }

    ll pref_sum(int i) {
        int b = i / k;
        ll res = pref[i] + 1ll * A[b] * (i - max(1, b * k) + 1);
        if (b > 0) res += PREF[b - 1];
        return res;
    }
};

struct input {
    int n, m, q;
    vector<ll> a, b;
    vector<tuple<int, int, int>> ops;

    input() = default;

    void read() {
        cin >> n >> m >> q;
        a.resize(n + 1);
        b.resize(m + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        ops.resize(q);
        for (auto& [type, k, d] : ops)
            cin >> type >> k >> d;
    }

    void print() {
        cout << n << " " << m << " " << q << "\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
        for (int i = 1; i <= m; i++)
            cout << b[i] << " ";
        cout << "\n";
        for (auto [type, k, d] : ops)
            cout << type << " " << k << " " << d << "\n";
    }

    void gen() {
        static mt19937_64 rnd(42);
        const int MAXN = 100;
        const ll MAXX = 1000;
        n = rnd() % MAXN + 2;
        m = rnd() % MAXN + 2;
        q = rnd() % MAXN + 2;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            ll lb = a[i - 1];
            if (i >= 2)
                lb = max(a[i - 1] - a[i - 2] + a[i - 1], lb);
            a[i] = lb + 1 + rnd() % MAXX + 1;
        }
        b.resize(m + 1);
        for (int i = 1; i <= m; i++) {
            ll lb = b[i - 1];
            if (i >= 2)
                lb = max(b[i - 1] - b[i - 2] + b[i - 1], lb);
            b[i] = lb + 1 + rnd() % MAXX + 1;
        }
        ops.resize(q);
        for (auto& [type, k, d] : ops) {
            type = rnd() % 2 + 1;
            d = rnd() % MAXX + 1;
            if (type == 1) k = rnd() % n + 1;
            else k = rnd() % m + 1;
        }
    }

    output fast() {
        vector<ll> res;
        vector<ll> da(n + 1), db(m + 1);
        for (int i = 2; i <= n; i++)
            da[i] = a[i] - a[i - 1];
        for (int i = 2; i <= m; i++)
            db[i] = b[i] - b[i - 1];
        SQRT sq(db);
        vector<int> used(m + 1);
        int timer = 10;
        ll sumb = 0;
        for (int i = 1; i <= m; i++)
            sumb += b[i];
        ll b1 = b[1];
        for (auto [type, k, d] : ops) {
            if (type == 1) {
                for (int coef = 1, j = n - k + 1; j <= n; j++, coef++) {
                    a[j] += 1ll * coef * d;
                    da[j] += d;
                }
            } else {
                sumb += 1ll * d * k * (k + 1) / 2;
//                for (int coef = 1, j = m - k + 1; j <= m; j++, coef++) {
//                    b[j] += 1ll * coef * d;
//                    db[j] += d;
//                }
                sq.update(m - k + 1, d);
            }
            int i = n, j = m;
            ll tot = a[i] + sumb;
            timer++;
            while (i > 1 && j > 1) {
                if (da[i] < sq.get(j)) {
                    int J;
                    if (da[i] < sq.get(1)) J = 2;
                    else {
                        int bl = 1, br = j, bm;
                        while (br - bl > 1) {
                            bm = (bl + br) >> 1;
                            if (da[i] < sq.get(bm)) br = bm;
                            else bl = bm;
                        }
                        J = br;
                    }
                    tot += 1ll * max(0, j - J + 1) * a[i];
                    j = J - 1;
                }
                if (j == 1) break;
                i--;
                tot += a[i] + sq.pref_sum(j) + b1;
            }
            tot += (sq.pref_sum(1) + b1) * (i - 1) + a[1] * (j - 1);
            while (i > 1) i--, tot += a[i];
            res.push_back(tot);
        }
        return output{res};
    }

    output slow() {
        vector<ll> res;
        for (auto [type, k, d] : ops) {
            if (type == 1) {
                for (int coef = 1, j = n - k + 1; j <= n; j++, coef++)
                    a[j] += 1ll * coef * d;
            } else {
                for (int coef = 1, j = m - k + 1; j <= m; j++, coef++)
                    b[j] += 1ll * coef * d;
            }
            int i = n, j = m;
            ll tot = a[i] + b[j];
            while (i > 1 || j > 1) {
                if (i > 1 && (j == 1 || a[i - 1] + b[j] < a[i] + b[j - 1])) {
                    i--;
                } else {
                    j--;
                }
                tot += a[i] + b[j];
            }
            res.push_back(tot);
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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}