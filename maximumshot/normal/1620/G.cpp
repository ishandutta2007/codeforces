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

vector<int> conv(int n, vector<int> f) {
    vector<vector<int>> dp(2, vector<int>(1 << n));
    dp[n & 1] = f;
    for (int c = n - 1; c >= 0; c--) {
        for (int mask = 0; mask < (1 << n); mask++) {
            dp[c & 1][mask] = dp[(c & 1) ^ 1][mask];
            if ((1 << c) & mask)
                inc_(dp[c & 1][mask], dp[(c & 1) ^ 1][mask ^ (1 << c)]);
        }
    }
    return dp[0];
}

struct output {
    ll res = 0;

    void print() {
        cout << res << "\n";
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<vector<int>> cnt;

    input() = default;

    void read() {
        cin >> n;
        cnt.resize(n, vector<int>(26, 1));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (char c : s)
                cnt[i][c - 'a']++;
        }
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        vector<int> intersect(1 << n, 1), mn, bit(1 << n), cnt_bit(1 << n);
        for (int i = 0; i < n; i++)
            bit[1 << i] = i;
        for (int mask = 1; mask < (1 << n); mask++) {
            int i = bit[mask & -mask];
            cnt_bit[mask] = cnt_bit[mask ^ (1 << i)] + 1;
        }
        for (int c = 0; c < 26; c++) {
            mn.assign(1 << n, inf);
            for (int mask = 1; mask < (1 << n); mask++) {
                int i = bit[mask & -mask];
                mn[mask] = min(mn[mask ^ (1 << i)], cnt[i][c]);
            }
            for (int mask = 1; mask < (1 << n); mask++)
                intersect[mask] = mul_(intersect[mask], mn[mask]);
        }
        intersect[0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            if (cnt_bit[mask] % 2 == 0)
                intersect[mask] = sub_(0, intersect[mask]);
        }
        vector<int> f = conv(n, intersect);
        vector<int> sum_ind(1 << n);
        for (int mask = 1; mask < (1 << n); mask++) {
            int i = bit[mask & -mask];
            sum_ind[mask] = sum_ind[mask ^ (1 << i)] + (i + 1);
        }
        ll res = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            ll x = 1ll * f[mask] * cnt_bit[mask] * sum_ind[mask];
            res ^= x;
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