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

const int N = 1e6 + 5;

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

int n;
int f[N][2][2]; // [size][left parity][root parity]

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    f[1][0][0] = 1;
    f[1][1][1] = 1;

    f[0][0][0] = 1;
    f[0][0][1] = 1;
    f[0][1][0] = 1;
    f[0][1][1] = 1;

    for (int k = 2; k <= n; k++) {
        int lk = k / 2 - 2;
        int rk = k / 2 + 2;

        lk = max(lk, 1);
        rk = min(rk, k);

        for (int mk = lk; mk <= rk; mk++) {
            int left_size = mk - 1;
            int right_size = k - mk;
            if (abs(left_size - right_size) > 1) continue;
            for (int left_parity = 0; left_parity < 2; left_parity++) {
                int root_parity = 1 ^ left_parity ^ (mk & 1);
                _inc(
                    f[k][left_parity][root_parity],
                    _mul(
                        f[left_size][left_parity][root_parity ^ 1],
                        f[right_size][root_parity ^ 1][root_parity]
                    )
                );
            }
        }
    }

    int res = _sum(f[n][1][0], f[n][1][1]);

    cout << res << "\n";

    return 0;
}