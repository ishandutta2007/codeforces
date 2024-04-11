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
    vector<int> t;

    RangeTree(int nn) {
        n = nn;
        t.resize(2 * n, -inf);
    }

    void set(int i, int x) {
        for (i += n, t[i] = max(t[i], x), i >>= 1; i > 0; i >>= 1)
            t[i] = max(t[i << 1], t[i << 1 | 1]);
    }

    int get(int l, int r) {
        int res = -inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n);
        for (auto& x : a) {
            cin >> x;
            x--;
        }
    }

    void print() {
        cout << n << "\n";
        for (auto x : a)
            cout << x + 1 << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 15;
        n = rnd() % MAXN + 1;
        a.resize(n);
        for (auto& x : a)
            x = rnd() % n;
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> dp(n), fi(n);
        for (int i = n - 1; i >= 0; i--)
            fi[a[i]] = i;
        RangeTree rt(n);
        for (int i = 0; i < n; i++) {
            if (i) dp[i] = dp[i - 1];
            int j = fi[a[i]];
            dp[i] = max(dp[i], (j > 0 ? dp[j - 1] : 0) + i - j - 1);
//            int mx = -inf;
//            for (int q = j + 1; q < i; q++)
//                mx = max(mx, dp[q] - q);
            int mx = j + 1 <= i - 1 ? rt.get(j + 1, i - 1) : -inf;
            dp[i] = max(dp[i], i - 1 + mx);
            rt.set(i, dp[i] - i);
        }
        return output{dp[n - 1]};
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
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask)
                    continue;
                for (int j = i + 1; j < n; j++) {
                    if ((1 << j) & mask)
                        continue;
                    if (a[i] != a[j])
                        continue;
                    for (int q = i + 1; q < j; q++)
                        dp[mask | (1 << q)] = 1;
                }
            }
        }
        int res = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask])
                res = max(res, __builtin_popcount(mask));
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