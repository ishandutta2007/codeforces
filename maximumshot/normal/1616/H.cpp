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

const int LOG = 30;

struct input {
    int n, x;
    vector<int> a;

    vector<int> pw2;

    input() = default;

    void read() {
        cin >> n >> x;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void print() {
        cout << n << " " << x << "\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 15;
        const int MAXLOG = 30;
        n = rnd() % MAXN + 1;
        x = rnd() % (1 << MAXLOG);
        a.resize(n);
        for (int i = 0; i < n; i++)
            a[i] = rnd() % (1 << MAXLOG);
    }

    void gen_max_test() {

    }

    void precalc() {
        pw2.assign(n + 1, 0);
        pw2[0] = 1;
        for (int i = 1; i < (int) pw2.size(); i++)
            pw2[i] = mul_(pw2[i - 1], 2);
    }

    int solve(vector<int> ar0, vector<int> ar1, int bit) {
        if (ar0.empty() || ar1.empty()) return 0;
        bit--;
        vector<int> l0, l1, r0, r1;
        for (auto val : ar0) {
            if ((1 << bit) & val) l1.push_back(val);
            else l0.push_back(val);
        }
        for (auto val : ar1) {
            if ((1 << bit) & val) r1.push_back(val);
            else r0.push_back(val);
        }
        if (!((1 << bit) & x)) {
            if (bit > 0) return sum_(solve(l0, r0, bit), solve(l1, r1, bit));
            else {
                int res = 0;
                inc_(res, mul_(sub_(pw2[l0.size()], 1), sub_(pw2[r0.size()], 1)));
                inc_(res, mul_(sub_(pw2[l1.size()], 1), sub_(pw2[r1.size()], 1)));
                return res;
            }
        }
        if (bit == 0) {
            return mul_(sub_(pw2[ar0.size()], 1), sub_(pw2[ar1.size()], 1));
        }
        int res = 0;
        int L0 = sub_(pw2[l0.size()], 1);
        int L1 = sub_(pw2[l1.size()], 1);
        int R0 = sub_(pw2[r0.size()], 1);
        int R1 = sub_(pw2[r1.size()], 1);
        int c01 = solve(l0, r1, bit);
        int c10 = solve(l1, r0, bit);
        inc_(res, mul_(L0, R0));
        inc_(res, mul_(L1, R1));
        inc_(res, c01);
        inc_(res, c10);
        inc_(res, mul_(c01, sum_(R0, L1)));
        inc_(res, mul_(c10, sum_(L0, R1)));
        inc_(res, mul_(c01, c10));
        return res;
    }

    output fast() {
        precalc();
        sort(a.begin(), a.end());
        if (x == 0) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                int j = i;
                while (j < n && a[i] == a[j]) j++;
                j--;
                inc_(res, sub_(pw2[j - i + 1], 1));
                i = j;
            }
            return output{res};
        }
        int high = LOG - 1, high_mask = 0;
        while (!((1 << high) & x)) {
            high_mask |= 1 << high;
            high--;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            vector<int> ar0, ar1;
            while (j < n && (a[i] & high_mask) == (a[j] & high_mask)) {
                if ((1 << high) & a[j]) ar1.push_back(a[j]);
                else ar0.push_back(a[j]);
                j++;
            }
            j--;
            inc_(res, sub_(pw2[ar0.size()], 1));
            inc_(res, sub_(pw2[ar1.size()], 1));
            inc_(res, solve(ar0, ar1, high));
            i = j;
        }
        return output{res};
    }

    output slow() {
        int res = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int ok = 1;
            vector<int> b;
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask)
                    b.push_back(a[i]);
            }
            for (auto v1 : b) {
                for (auto v2 : b) {
                    if ((v1 ^ v2) > x)
                        ok = 0;
                }
            }
            inc_(res, ok);
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