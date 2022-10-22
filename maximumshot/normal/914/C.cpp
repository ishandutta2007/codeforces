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

const int N = 1005;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> C(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = _sum(C[i - 1][j - 1], C[i - 1][j]);
    }

    vector<int> dp(N);
    for (int i = 2; i < N; i++)
        dp[i] = dp[__builtin_popcount(i)] + 1;

    int res = 0;
    string n;
    int k;
    cin >> n >> k;

    ll nn = 0;
    for (char c : n)
        nn = min(inf64, nn * 2 + c - '0');

    for (int x = 1; x < N; x++) {
        if (dp[x] == k && x <= nn)
            _inc(res, 1);
    }

    if (N <= nn) {
        for (int x = 1; x < N; x++) {
            if (dp[x] + 1 == k) {
//                for (ll y = 0; y <= nn; y++) {
//                    if (__builtin_popcountl(y) == x)
//                        _inc(res, 1);
//                }
                int c = 0;
                for (int i = 0; i < (int) n.size() && c <= x; i++) {
                    if (n[i] == '1') {
                        int rem = (int) n.size() - i - 1;
                        _inc(res, C[rem][x - c]);
                        c++;
                    }
                }
                if (c == x)
                    _inc(res, 1);
                for (int y = 0; y < N; y++) {
                    if (__builtin_popcount(y) == x)
                        _dec(res, 1);
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}