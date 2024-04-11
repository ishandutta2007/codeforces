#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

template <int mod, int root, int LOG, int N>
struct FFT {
    vector<int> G[LOG + 1];
    vector<int> rev[LOG + 1];

    FFT() {
        for (int start = root, lvl = LOG; lvl >= 0;
            lvl--, start = _mul(start, start)) {
            int tot = 1 << lvl;
            G[lvl].resize(tot);
            for (int cur = 1, i = 0; i < tot;
                i++, cur = _mul(cur, start)) {
                G[lvl][i] = cur;
            }
        }
        for (int lvl = 1; lvl <= LOG; lvl++) {
            int tot = 1 << lvl;
            rev[lvl].resize(tot);
            for (int i = 1; i < tot; i++) {
                rev[lvl][i] = ((i & 1) << (lvl - 1)) |
                            (rev[lvl][i >> 1] >> 1);
            }
        }
    }

    void fft(vector<int>& a, int sz, bool invert) {
        int n = 1 << sz;
        for (int j, i = 0; i < n; i++) {
            if ((j = rev[sz][i]) < i) {
                swap(a[i], a[j]);
            }
        }
        for (int f1, f2, lvl = 0, len = 1; len < n;
            len <<= 1, lvl++) {
            for (int i = 0; i < n; i += (len << 1)) {
                for (int j = 0; j < len; j++) {
                    f1 = a[i + j];
                    f2 = _mul(a[i + j + len], G[lvl + 1][j]);
                    a[i + j] = _sum(f1, f2);
                    a[i + j + len] = _sub(f1, f2);
                }
            }
        }
        if (invert) {
            reverse(a.begin() + 1, a.end());
            int rn = _div(1, n);
            for (int i = 0; i < n; i++) {
                a[i] = _mul(a[i], rn);
            }
        }
    }

    vector<int> multiply(const vector<int>& a,
                        const vector<int>& b) {
        vector<int> fa(a.begin(), a.end());
        vector<int> fb(b.begin(), b.end());
        int n = (int) a.size();
        int m = (int) b.size();
        int maxnm = max(n, m), sz = 0;
        while ((1 << sz) < maxnm) sz++; sz++;
        fa.resize(1 << sz);
        fb.resize(1 << sz);
        fft(fa, sz, false);
        fft(fb, sz, false);
        int SZ = 1 << sz;
        for (int i = 0; i < SZ; i++) {
            fa[i] = _mul(fa[i], fb[i]);
        }
        fft(fa, sz, true);
        while ((int) fa.size() > 1 && !fa.back())
            fa.pop_back();
        return fa;
    }

    vector<int> series_inverse(const vector<int>& series, int n) {
        vector<int> current = {_div(1, series[0])};
        vector<int> A = {};
        int l = 0;
        while ((int) current.size() < n) {
            while (l < 2 * (int) current.size()) {
                A.push_back(l < (int) series.size() ? series[l] : 0);
                l++;
            }
            vector<int> next = multiply(A, current);
            for (int& x : next) x = _sub(0, x);
            next[0] = _sum(2, next[0]);
            next = multiply(next, current);
            next.resize(2 * current.size());
            current = next;
        }
        current.resize(n);
        return current;
    }
};

FFT<998244353, 31, 23, int(2e5 + 5)> fft;

int slow(int n, int m) {
    int res = 0;
    for (int x = 0; x < m; x++) {
        vector<vector<int>> dp(n + 1, vector<int>(m));
        dp[0][x] = 1;
        for (int i = 2; i <= n; i += 2) {
            dp[i] = dp[i - 2];
            for (int z = 1; z < m; z++)
                _inc(dp[i][z], dp[i][z - 1]);
            for (int z = m - 2; z >= 0; z--)
                _inc(dp[i][z], dp[i][z + 1]);
        }
        if (n % 2) {
            dp[n] = dp[n - 1];
            for (int z = 1; z < m; z++)
                _inc(dp[n][z], dp[n][z - 1]);
            reverse(dp[n].begin(), dp[n].end());
        }
        _inc(res, dp[n][x]);
    }
    return res;
}

vector<int> SUM(const vector<int>& a, const vector<int>& b) {
    vector<int> res = a;
    for (int i = 0; i < (int) res.size(); i++)
        _inc(res[i], b[i]);
    return res;
}

vector<int> MUL(const vector<int>& a, const vector<int>& b) {
    vector<int> res(a.size());
    for (int i = 0; i < (int) a.size(); i++) {
        for (int j = 0; j < (int) b.size(); j++) {
            if (i + j < (int) res.size())
                _inc(res[i + j], _mul(a[i], b[j]));
        }
    }
    return res;
}

vector<int> LINEAR(const vector<int>& a, int k, int b) {
    vector<int> res = a;
    for (auto& x : res)
        x = _sum(_mul(x, k), b);
    return res;
}

pair<vector<int>, vector<int>> SPLIT(const vector<int>& a) {
    vector<int> O(a.size()), E(a.size());
    for (int i = 0; i < (int) a.size(); i++) {
        if (i % 2) {
            O[i] = a[i];
        } else {
            E[i] = a[i];
        }
    }
    return make_pair(E, O);
}

vector<int> solve_slow(int n, int m) {
    vector<int> res(n + 1);
    vector<int> ar(n + 1);
    function<void(int)> rec = [&](int i) {
        _inc(res[i], 1);
        if (i == n) return;
        for (ar[i + 1] = 0; ar[i + 1] < m; ar[i + 1]++) {
            if (i > 0 && ar[i] + ar[i + 1] >= m)
                break;
            rec(i + 1);
        }
    };
    rec(0);
    return res;
}

const int MAXN = 5e4 + 5;
unordered_map<ll, vector<int>> MEM;

vector<int> solve(int n, int m) {
    ll h = 1ll * m * MAXN + n;
    {
        auto fnd = MEM.find(h);
        if (fnd != MEM.end())
            return fnd->second;
    }
    if (m == 1) {
        return vector<int>(n + 1, 1);
    }
    vector<int> seq = solve(n, m / 2);
    if (m % 2) _inc(seq[1], 1);
    auto [E, O] = SPLIT(seq);
    vector<int> only_odd(n + 1);
    { // 1 + O + O^2 + ... = 1 / (1 - O)
        vector<int> cur(n + 1);
//        cur[0] = 1;
//        for (int i = 0; i <= n; i++) {
//            only_odd = SUM(only_odd, cur);
//            cur = MUL(cur, O);
//        }
        for (int i = 0; i <= n; i++)
            cur[i] = _sub(0, O[i]);
        _inc(cur[0], 1);
        cur = fft.series_inverse(cur, n + 1);
        only_odd = cur;
    }
//    only_odd[0] = 1;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= i; j += 2) {
//            _inc(only_odd[i], _mul(only_odd[i - j], O[j]));
//        }
//    }
    vector<int> one_even(n + 1), two_even(n + 1);
//    {
//        int hlp = E[0];
//        one_even = MUL(E, only_odd);
//        E[0] = hlp;
//    }
    E[0] = 0;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j <= i; j++) {
//            _inc(one_even[i], _mul(E[j], only_odd[i - j]));
//        }
//    }

    int sz = 1;
    while ((1 << sz) <= 3 * n) sz++; sz++;
    vector<int> fE = E, fonly_odd = only_odd;
    E.resize(1 << sz);
    only_odd.resize(1 << sz);
    fft.fft(E, sz, false);
    fft.fft(only_odd, sz, false);

    one_even = E;
    two_even = E;
    for (int i = 0; i < (1 << sz); i++) {
        one_even[i] = _mul(E[i], only_odd[i]);
        two_even[i] = _mul(_mul(E[i], E[i]), only_odd[i]);
    }

    fft.fft(one_even, sz, true);
    fft.fft(two_even, sz, true);

    one_even.resize(n + 1);
    two_even.resize(n + 1);

    E = fE;
    only_odd = fonly_odd;

//    one_even = MUL(E, only_odd);
//    two_even = MUL(MUL(E, E), only_odd);

//    for (int i = 0; i <= n; i++) {
//        for (int x = 0; x <= i; x++) {
//            for (int y = 0; x + y <= i; y++) {
//                _inc(two_even[i], _mul(_mul(E[x], E[y]), only_odd[i - x - y]));
//            }
//        }
//    }
    vector<int> res(n + 1);
    for (int i = 0; i <= n; i++) {
        res[i] = (O[i] + only_odd[i] + 2ll * one_even[i] + two_even[i]) % mod;
    }
    res[1] = m;

    MEM[h] = res;

    return res;
}

int fast(int n, int m) {
    if (m == 1) {
        return 1;
    }
    int res = 0;
    if (n % 2 == 0) {
        _inc(res, _mul(2, fast(n, m / 2)));
    }
    vector<int> seq = solve(n, m / 2);
    if (m % 2) _inc(seq[1], 1);
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0)
            seq[i] = 0;
    }
    vector<int> dp(n + 1);
    { // 1 / (1 - seq)
        vector<int> cur(n + 1);
//        cur[0] = 1;
//        for (int i = 0; i <= n; i++) {
//            dp = SUM(dp, cur);
//            cur = MUL(cur, seq);
//        }
        for (int i = 0; i <= n; i++)
            cur[i] = _sub(0, seq[i]);
        _inc(cur[0], 1);
        cur = fft.series_inverse(cur, n + 1);
        dp = cur;
    }
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= i; j++)
//            _inc(dp[i], _mul(dp[i - j], seq[j]));
//    }
    for (int a = 1; a <= n; a++) {
        if (a % 2)
            _inc(res, _mul(a, _mul(seq[a], dp[n - a])));
    }
    return res;
}

void work() {
    int n, m;
    cin >> n >> m;
    int res = fast(n, m);
    cout << res << "\n";
//#ifdef DEBUG
//    cout << "slow = " << slow(n, m) << "\n";
//#endif
}

void test() {
    for (int n = 2; n <= 50; n++) {
        for (int m = 1; m <= 50; m++) {
            int fs = fast(n, m);
            int sl = slow(n, m);
            if (fs != sl) {
                cout << "WA\n";
                cout << "exp = " << sl << "\n";
                cout << "fnd = " << fs << "\n";
                cout << n << " " << m << "\n";
                return;
            } else {
                cout << "OK " << fs << endl;
            }
        }
    }
    cout << "OK\n";
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