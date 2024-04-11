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

const int N = 55;

vector<vector<int>> calc1(int m, int num, int denum) {
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            int p = _mul(num + j, _binpow(denum + i, mod - 2));
            _inc(dp[i + 1][j + 1], _mul(dp[i][j], p));
            _inc(dp[i + 1][j], _mul(dp[i][j], _sub(1, p)));
        }
    }
    return dp;
}

vector<vector<int>> calc0(int m, int num, int denum) {
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            int p = _mul(num - j, _binpow(denum - i, mod - 2));
            _inc(dp[i + 1][j + 1], _mul(dp[i][j], p));
            _inc(dp[i + 1][j], _mul(dp[i][j], _sub(1, p)));
        }
    }
    return dp;
}

vector<vector<int>> main_calc(int m, int num, int denum) {
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            int p = _mul(num + j, _binpow(denum + j - (i - j), mod - 2));
            _inc(dp[i + 1][j + 1], _mul(dp[i][j], p));
            _inc(dp[i + 1][j], _mul(dp[i][j], _sub(1, p)));
        }
    }
    return dp;
}

int n, m;
int a[N], w[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    int num = 0, denum = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            _inc(num, w[i]);
        }
        _inc(denum, w[i]);
    }

    vector<vector<int>> main_dp = main_calc(m, num, denum), dp;

    for (int i = 1; i <= n; i++) {
        int ri = 0;
        dp = a[i] ? calc1(m, w[i], num) : calc0(m, w[i], denum - num);
        for (int j = 0; j <= m; j++) {
            int ml = a[i] ? main_dp[m][j] : main_dp[m][m - j];
            for (int c = 0; c <= j; c++) {
                _inc(ri, _mul(_mul(ml, dp[j][c]), w[i] + (a[i] ? c : -c)));
            }
        }
        cout << ri << "\n";
    }

    return 0;
}