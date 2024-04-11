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

const int N = 1e5 + 5;

int dp[N][2];
int f[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < N; i++) {
        dp[i][0] = _sum(dp[i - 1][1], dp[i - 2][1]);
        dp[i][1] = _sum(dp[i - 1][0], dp[i - 2][0]);
    }

    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i < N; i++) {
        f[i] = _sum(f[i - 1], f[i - 2]);
    }

    int n, m;
    cin >> n >> m;

    int res = 0;

    int cn = _sum(dp[n][0], dp[n][1]);
    int cm = _sum(dp[m][0], dp[m][1]);

    _inc(res, _sub(cn, 2));
    _inc(res, _sub(cm, 2));
    _inc(res, 2);

    cout << res << "\n";

    return 0;
}