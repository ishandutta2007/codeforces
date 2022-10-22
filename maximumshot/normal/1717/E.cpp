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

const int mod = inf + 7;

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
        throw;
    }
};

struct input {
    int n;

    input() = default;

    void read() {
        cin >> n;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        vector<int> F(n + 1);
        for (int i = 1; i <= n; i++) {
            inc_(F[i], i - 1);
            for (int j = 2 * i; j <= n; j += i)
                dec_(F[j], F[i]);
        }
//        for (int a = 1; a <= n; a++) {
//            for (int b = 1; a + b <= n; b++) {
//                if (__gcd(a, b) == 1)
//                    inc_(F[a + b], 1);
//            }
//        }
        int res = 0;
        vector<vector<int>> d(n + 1);
        for (int x = 1; x <= n; x++) {
            for (int y = x; y <= n; y += x)
                d[y].push_back(x);
        }
        for (int G = 1; G <= n; G++) {
            for (int c = G; c <= n; c += G) {
                int tmp = (n - c);
                if (tmp % G) continue;
                tmp /= G;
                int c2 = c / G;
                int add = 0;
                for (int k : d[tmp]) {
                    if (__gcd(k, c2) != 1) continue;
                    inc_(add, mul_(k, F[tmp / k]));
                }
                inc_(res, mul_(add, mul_(G, c2)));
            }
        }
        return output{res};
    }

#ifdef DEBUG
    output slow() {
        int res = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; a + b < n; b++) {
                int c = n - a - b;
                int g = __gcd(a, b);
                int G = __gcd(g, c);
                int ml = mul_(c / G, g);
                inc_(res, ml);
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