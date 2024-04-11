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

void upd(ll& x, ll y) {
    if (x > y)
        x = y;
}

struct input {
    int n;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        b.resize(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        const int MAXS = 2e4 + 5;
        vector<int> sa(n + 1), sb(n + 1);
        vector<ll> sum_sqr_a(n + 1), sum_sqr_b(n + 1);
        for (int i = 0; i < n; i++) {
            sa[i + 1] = sa[i] + a[i];
            sb[i + 1] = sb[i] + b[i];

            sum_sqr_a[i + 1] = sum_sqr_a[i] + 1ll * a[i] * a[i];
            sum_sqr_b[i + 1] = sum_sqr_b[i] + 1ll * b[i] * b[i];
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(MAXS, inf64));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int SA = 0; SA < MAXS; SA++) {
                if (dp[i][SA] == inf64)
                    continue;
                int SB = sa[i] + sb[i] - SA;
                if (SB < 0 || SB >= MAXS)
                    continue;
                for (int it = 0; it < 2; it++) {
                    upd(
                            dp[i + 1][SA + a[i]],
                            dp[i][SA] +
                            sum_sqr_a[i] + sum_sqr_b[i] +
                            1ll * i * (1ll * a[i] * a[i] + 1ll * b[i] * b[i]) +
                            2ll * (1ll * a[i] * SA + 1ll * b[i] * SB)
                    );
                    swap(a[i], b[i]);
                }
            }
        }
        return output{*min_element(dp.back().begin(), dp.back().end())};
    }

    output slow() {
#ifndef DEBUG
        throw;
#endif
        return output();
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