#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _sum(int a, int b) {
    return (a + b < mod ? a + b : a + b - mod);
}

inline int _sub(int a, int b) {
    return (a >= b ? a - b : a - b + mod);
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline void _inc(int& x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int& x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

const int N = 1005;
const int X = 1e5 + 5;

int used[X];
int n, k;
int a[N];
int f[X], g[X];
int dp[N][N], sm[N][N];

int calc(int x) {
    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + k + 1, 0);
        fill(sm[i], sm[i] + k + 1, 0);
    }
    dp[0][0] = 1;
    sm[0][0] = 1;
    for (int j = 0, i = 1; i <= n; i++) {
        while (j + 1 <= i && a[i] - a[j + 1] >= x) j++;
        for (int c = 0; c < k; c++) {
            _inc(dp[i][c + 1], sm[j][c]);
        }
        for (int c = 0; c <= k; c++) {
            sm[i][c] = _sum(sm[i - 1][c], dp[i][c]);
        }
    }
    int res = 0;
    for (int i = k; i <= n; i++) {
        _inc(res, dp[i][k]);
    }
    return res;
}

bool can(int x) {
    int cnt = 0;
    int i = 1;
    while (i <= n) {
        cnt++;
        int j = lower_bound(a + 1, a + n + 1, a[i] + x) - a;
        j = max(j, i + 1);
        i = j;
    }
    return cnt >= k;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i < j; i++) {
            used[a[j] - a[i]] = 1;
        }
    }

    int bx = 1;
    while (can(bx)) bx <<= 1;

    bx = min(bx, X - 1);

    for (int x = 0; x <= bx; x++) {
        if (!used[x]) continue;
        f[x] = calc(x);
    }

    for (int sum = 0, i = bx; i >= 0; i--) {
        if (!used[i]) continue;
        g[i] = _sub(f[i], sum);
        _inc(sum, g[i]);
    }

    int res = 0;

    for (int x = 0; x <= bx; x++) {
//        if (g[x])
//        cout << x << " : " << g[x] << "\n";
        _inc(res, _mul(x, g[x]));
    }

    cout << res << "\n";

    return 0;
}