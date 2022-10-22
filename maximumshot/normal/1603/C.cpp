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
    int res = 0;

    output() = default;

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

const int LOG = 20;

struct RangeTree {
    int n = 0; // [1, n]
    vector<vector<int>> g;
    vector<int> log_;

    RangeTree() = default;

    RangeTree(const vector<int>& a) {
        n = (int) a.size() - 1;
        g.resize(LOG, vector<int>(n + 1));
        g[0] = a;
        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                g[j][i] = gcd(g[j - 1][i], g[j - 1][i + (1 << (j - 1))]);
            }
        }
        log_.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            log_[i] = log_[i - 1] + 1;
            if ((1 << log_[i]) > i)
                log_[i]--;
        }
    }

    int get(int i, int x) {
        int bl = 0, br = i, bm, k;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;

            // [bm, i]
            k = log_[i - bm + 1];
            if (g[k][bm] % x == 0 && g[k][i - (1 << k) + 1] % x == 0)
                br = bm;
            else
                bl = bm;
        }
        return br;
    }
};

const int X = 1e5 + 100;
int rev[X];

void precalc() {
    for (int x = 0; x < X; x++)
        rev[x] = binpow_(x, mod - 2);
}

struct input {
    int n;
    vector<int> a;

    input() = default;

    void read() {
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void print() {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    void gen() {
        static mt19937 rnd(42);
        const int MAXN = 100;
        const int MAXX = 1e5;
        n = rnd() % MAXN + 1;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % MAXX + 1;
    }

    void gen_max_test() {
        static mt19937 rnd(42);
        const int MAXX = 1e5;
        n = 1e5;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % MAXX + 1;
    }

    output fast() {
        vector<int> A(n + 1);
        for (int i = 1; i <= n; i++)
            A[i] = sum_(A[i - 1], mul_(a[i], i));
        unordered_map<int, int> dp, nxt;
        int tot = 0;
        for (int i = n; i >= 1; i--) {
            nxt.clear();
            dp[1e5 + 10]++;
            for (auto [cur, val] : dp) {
                int cnt = (a[i] + cur - 1) / cur;
                inc_(tot, mul_(cnt - 1, mul_(val, i)));
                int next_cur = a[i] / cnt;
                inc_(nxt[next_cur], val);
            }
            swap(dp, nxt);
        }
        return output{tot};
    }

    output slow() {
        int res = 0;
        vector<int> A(n + 1);
        for (int i = 1; i <= n; i++)
            A[i] = sum_(A[i - 1], mul_(a[i], i));
        RangeTree rt(a);
        for (int r = 1; r <= n; r++) {
            int cur = 1e5 + 10;
            for (int l = r; l >= 1; l--) {
                int cnt = (a[l] + cur - 1) / cur;
                inc_(res, mul_(cnt - 1, l));
                cur = a[l] / cnt;
            }
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
    while (1) {
        input in;
        in.gen();
        output fs = in.fast();
        output sl = in.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA\n";
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
    output fs = in.fast();
    fs.print();
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    work();
//    test();
//    max_test();

    return 0;
}