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

const int mod = inf + 7;

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

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        int res = 1;
        vector<int> c(n, 1), cc;
        for (int j = 0, i = k - 1; i >= 1; i--, j ^= 1) {
            cc.assign(n, 0);
            for (int q = 0; q < n; q++)
                _inc(res, c[q]);
            if (j == 0) { // left
                for (int q = n - 1; q > 0; q--) {
                    _inc(cc[q - 1], cc[q]);
                    _inc(cc[q - 1], c[q]);
                }
            } else { // right
                for (int q = 0; q + 1 < n; q++) {
                    _inc(cc[q + 1], cc[q]);
                    _inc(cc[q + 1], c[q]);
                }
            }
            c = cc;
        }
        cout << res << "\n";
    }

    return 0;
}