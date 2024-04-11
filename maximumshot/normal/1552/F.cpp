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

const int mod = 998244353;

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

struct input {
    int n;
    vector<int> x, y, s;

    input() = default;

    void read() {
        cin >> n;
        x.resize(n);
        y.resize(n);
        s.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> s[i];
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> link(n), len(n);
        for (int i = 0; i < n; i++) {
            link[i] = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
            len[i] = x[link[i]] - y[i];
        }
        vector<int> dp(n), sm(n);
        for (int i = 0; i < n; i++) {
            int j = link[i];
            if (i == j) {
                dp[i] = len[i];
            } else {
                dp[i] = sum_(len[i], x[i] - x[j]);
                inc_(dp[i], sm[i - 1]);
                if (j > 0) dec_(dp[i], sm[j - 1]);
            }
            sm[i] = dp[i];
            if (i) inc_(sm[i], sm[i - 1]);
        }
        int res = sum_(1, x[n - 1]);
        int cur = 0;
//        while (1) {
//            if (cur == n - 1 && s[cur] == 0) break;
//            if (s[cur] == 0) {
//                s[cur] = 1;
//                inc_(res, x[cur + 1] - x[cur]);
//                cur++;
//            } else {
//                s[cur] = 0;
//                inc_(res, len[cur]);
//                cur = link[cur];
//            }
//        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 1)
                inc_(res, dp[i]);
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        return output();
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