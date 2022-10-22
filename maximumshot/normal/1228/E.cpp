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

const int mod = inf + 7;
const int N = 255;

int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = (1ll * res * tmp) % mod;
        }
        tmp = (1ll * tmp * tmp) % mod;
        pw >>= 1;
    }
    return res;
}

int n, k;
int pw0[N * N];
int pw1[N * N];
int C[N][N];
int f[N][N];
int fact[N];
int rfact[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    pw0[0] = 1;
    pw1[0] = 1;

    for (int i = 1; i < N * N; i++) {
        pw0[i] = (1ll * pw0[i - 1] * k) % mod;
        pw1[i] = (1ll * pw1[i - 1] * (k - 1)) % mod;
    }

    for (int i = 0; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            if (C[i][j] >= mod) C[i][j] -= mod;
        }
    }

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    }
    for (int i = 0; i <= n; i++) {
        rfact[i] = _binpow(fact[i], mod - 2);
    }

    int res = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int sign = (i + j) % 2 ? mod - 1 : 1;
            int m1 = (1ll * pw0[(n-i)*(n-j)] * pw1[(i+j)*n-i*j]) % mod;
            m1 = (1ll * m1 * sign) % mod;
            m1 = (1ll * m1 * C[n][i]) % mod * C[n][j] % mod;
            res += m1;
            if (res >= mod) res -= mod;
        }
    }

    cout << res << "\n";

    return 0;
}