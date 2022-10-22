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
    int res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

vector<vector<int>> calc(string sa, string sb, vector<int> a, vector<int> b) {
    int n = (int) sa.size();
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) {
                f[i][j] = 1;
            } else if (i == 0) {
                f[i][j] = sb[j - 1] != '?' && b[j - 1] == 1 ? 0 : f[i][j - 1];
            } else if (j == 0) {
                f[i][j] = sa[i - 1] != '?' && a[i - 1] == 1  ? 0 : f[i - 1][j];
            } else {
                // i, j > 0
                if (sa[i - 1] != '?') {
                    if (sb[j - 1] != '?') {
                        int x = a[i - 1], y = b[j - 1];
                        if (x == y)
                            f[i][j] = f[i - 1][j - 1];
                        else if (x)
                            f[i][j] = f[i][j - 1];
                        else if (y)
                            f[i][j] = f[i - 1][j];
                    } else {
                        int x = a[i - 1];
                        if (x)
                            f[i][j] = sum_(f[i - 1][j - 1], f[i][j - 1]);
                        else
                            f[i][j] = f[i - 1][j];
                    }
                } else {
                    if (sb[j - 1] != '?') {
                        int y = b[j - 1];
                        if (y)
                            f[i][j] = sum_(f[i - 1][j - 1], f[i - 1][j]);
                        else
                            f[i][j] = f[i][j - 1];
                    } else {
                        f[i][j] = sum_(f[i - 1][j], f[i][j - 1]);
                    }
                }
            }
        }
    }
    return f;
}

struct input {
    int n;
    string sa, sb;
    vector<int> a, b;

    input() = default;

    void read() {
        cin >> n >> sa >> sb;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        a.resize(n), b.resize(n);
        for (int i = 0; i < n; i++) {
            a[i] = sa[i] - '0';
            b[i] = sb[i] - '0';
            if (i % 2)
                a[i] ^= 1, b[i] ^= 1;
        }
        vector<vector<int>> f = calc(sa, sb, a, b), g;
        reverse(sa.begin(), sa.end());
        reverse(sb.begin(), sb.end());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        g = calc(sa, sb, a, b);
        reverse(sa.begin(), sa.end());
        reverse(sb.begin(), sb.end());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<int> xs, ys;
                if (sa[i] == '?') xs = {0, 1};
                else xs = {a[i]};
                if (sb[j] == '?') ys = {0, 1};
                else ys = {b[j]};
                for (int x : xs) {
                    for (int y : ys) {
                        if (x == 1 && y == 1) {
                            int pref = f[i][j];
                            int suff = g[n - i - 1][n - j - 1];
                            int dist = abs(i - j);
                            inc_(res, mul_(dist, mul_(pref, suff)));
                        }
                    }
                }
            }
        }
        return output{res};
    }

    output slow() {
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