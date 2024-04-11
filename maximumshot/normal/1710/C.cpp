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
        throw;
    }
};

struct input {
    string s;

    input() = default;

    void read() {
        cin >> s;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    void gen_max_test() {

    }

    output fast() {
        int n = (int) s.size();
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = s[i] - '0';
        reverse(a.begin(), a.end());
        {
            a.push_back(0); n++;
            int i = 0;
            while (a[i] == 1) a[i] = 0, i++;
            a[i]++;
            while (!a.back()) a.pop_back();
            n = (int) a.size();
        }
        vector<vector<int>> dp(n + 1, vector<int>(1 << 6));
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int mask = 0; mask < (1 << 6); mask++) {
                int ar[6];
                for (int j = 0; j < 6; j++) ar[j] = (mask >> j) & 1;
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        for (int z = 0; z < 2; z++) {
                            if (!ar[0] && x > a[i]) continue;
                            if (!ar[1] && y > a[i]) continue;
                            if (!ar[2] && z > a[i]) continue;
                            if (!ar[3] && (x ^ y) + (y ^ z) < (x ^ z)) continue;
                            if (!ar[4] && (x ^ y) + (x ^ z) < (y ^ z)) continue;
                            if (!ar[5] && (x ^ z) + (y ^ z) < (x ^ y)) continue;
                            int nmask = mask;
                            if (x < a[i]) nmask |= 1 << 0;
                            if (y < a[i]) nmask |= 1 << 1;
                            if (z < a[i]) nmask |= 1 << 2;
                            if ((x ^ y) + (y ^ z) > (x ^ z)) nmask |= 1 << 3;
                            if ((x ^ y) + (x ^ z) > (y ^ z)) nmask |= 1 << 4;
                            if ((x ^ z) + (y ^ z) > (x ^ y)) nmask |= 1 << 5;
                            inc_(dp[i][nmask], dp[i + 1][mask]);
                        }
                    }
                }
            }
        }
        int res = dp[0][(1 << 6) - 1];
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