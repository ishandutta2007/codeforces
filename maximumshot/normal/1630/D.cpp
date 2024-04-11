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

int gcd(int x, int y) {
    return !x ? y : gcd(y % x, x);
}

ll solve(vector<int> a, int g) {
    vector<vector<int>> seq(g);
    for (int i = 0; i < (int) a.size(); i++)
        seq[i % g].push_back(a[i]);
    ll res = 0;
    for (int r = 0; r < g; r++) {
        int cnt_neg = 0, cnt_zero = 0;
        for (auto x : seq[r]) {
            if (x == 0) cnt_zero++;
            if (x < 0) cnt_neg++;
        }
        if (cnt_neg % 2 == 0 || cnt_zero) {
            for (auto x : seq[r])
               res += abs(x);
        } else {
            ll mn = inf64;
            for (auto x : seq[r]) {
                x = abs(x);
                res += x;
                mn = min(mn, ll(x));
            }
            res -= 2 * mn;
        }
    }
    return res;
}

struct input {
    int n, m;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
    }

    void print() {
        cout << n << " " << m << "\n";
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        for (auto x : b)
            cout << x << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 5;
        const int MAXX = 5;
        n = rnd() % MAXN + 2;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % (2 * MAXX + 1) - MAXX;
        for (int i = 1; i <= n / 2; i++)
            b.push_back(i);
        shuffle(b.begin(), b.end(), rnd);
        m = rnd() % (int) b.size() + 1;
        b.resize(m);
    }

    void gen_max_test() {

    }

    output fast() {
        int g = 0;
        for (auto x : b)
            g = gcd(g, x);
        ll res = -inf64;
        res = max(res, solve(a, g));
        for (int i = 0; i < g; i++)
            a[i] = -a[i];
        res = max(res, solve(a, g));
        return output{res};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (!dp[mask])
                continue;
            for (int x : b) {
                for (int i = 0; i + x - 1 < n; i++) {
                    int tmp = 0;
                    for (int j = i; j < i + x; j++)
                        tmp |= 1 << j;
                    dp[mask ^ tmp] = 1;
                }
            }
        }
        ll res = -inf64;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (!dp[mask])
                continue;
            ll tmp = 0;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask) tmp -= a[i];
                else tmp += a[i];
            }
            res = max(res, tmp);
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