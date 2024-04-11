#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

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

const int N = 2005;

int fast(string s) {
    int n = (int) s.size();
    s = "#" + s;

    vector<int> f(n + 2);
    vector<vector<int>> pr(n + 1, vector<int>(n + 1));
    vector<vector<int>> sf(n + 2, vector<int>(n + 2));

    pr[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int was = 0; was <= n; was++) {
            if (s[i] == '(') {
                if (was < n)
                    _inc(pr[i][was + 1], pr[i - 1][was]);
            } else if (s[i] == ')') {
                _inc(pr[i][was], pr[i - 1][was]);
            } else {
                _inc(pr[i][was], pr[i - 1][was]);
                if (was < n)
                    _inc(pr[i][was + 1], pr[i - 1][was]);
            }
        }
    }

    sf[n + 1][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int was = 0; was <= n; was++) {
            if (s[i] == '(') {
                _inc(sf[i][was], sf[i + 1][was]);
            } else if (s[i] == ')') {
                if (was < n)
                    _inc(sf[i][was + 1], sf[i + 1][was]);
            } else {
                _inc(sf[i][was], sf[i + 1][was]);
                if (was < n)
                    _inc(sf[i][was + 1], sf[i + 1][was]);
            }
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        for (int j = n; j >= 1; j--)
            _inc(sf[i][j], sf[i][j + 1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= n; l++) {
            int m1 = s[i] == ')' ? 0 : pr[i - 1][l - 1];
            int m2 = sf[i + 1][l];
//            if (_mul(m1, m2))
//                cout << "add to l = " << l << " value = " << _mul(m1, m2) << ", where i = " << i << "\n";
            _inc(f[l], _mul(m1, m2));
        }
    }

    int res = 0;

    for (int l = 1; l <= n; l++) {
        int m = _sub(f[l], f[l + 1]);
        _inc(res, _mul(m, l));
    }

    return res;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
//    s.resize(2000, '?');
//    mt19937 rnd(42);
//    string buf = "()?";
//    for (char& c : s) {
//        c = buf[rnd() % 3];
//    }
    cout << fast(s) << "\n";

    return 0;
}