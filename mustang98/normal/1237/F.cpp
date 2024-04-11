#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 3620, max_2 = max_n / 2, inf = 1000111222, mod = 998244353;

bool ul[max_n];
bool ur[max_n];

int freel = 0, freer = 0;

int dpl[max_n][max_2];
int dpr[max_n][max_2];
int c[max_n][max_n];
ll f[max_n];

void init() {
    c[0][0] = 1;
    for (int i = 1; i < max_n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                c[i][j] = 1;
            } else {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % mod;
    }
}

int C(int n, int k) {
    if (n < 0 || k < 0) {
        exit(228);
    }
    if (k > n) {
        return 0;
    }
    return c[n][k];
}

void calcdp(int dp[max_n][max_2], bool used[max_n], int n) {
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= 1 && i >= 2 && !used[i] && !used[i - 1]) {
                dp[i][j] += dp[i - 2][j - 1];
            }
            if (j == 1 && i == 1 && !used[i] && !used[i - 1]) {
                dp[i][j] = 1;
            }
            dp[i][j] %= mod;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    init();
    int sl, sr, n;
    cin >> sl >> sr >> n;
    for (int i =0 ; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        ul[r] = 1;
        ur[c] = 1;
        cin >> r >> c;
        --r, --c;
        ul[r] = 1;
        ur[c] = 1;
    }
    for (int i =0 ; i < sl; ++i) {
        if (!ul[i]) {
            ++freel;
        }
    }
    for (int i = 0; i < sr; ++i) {
        if (!ur[i]) {
            ++freer;
        }
    }
    calcdp(dpl, ul, sl);
    //cout << sl << ' ' << sr << endl;
    calcdp(dpr, ur, sr);
    ll ans = 0;
    for (int c2l = 0; c2l <= sl / 2; ++c2l) {
        for (int c2r = 0; c2r <= sr / 2; ++c2r) {
            int suml = c2l * 2 + c2r;
            int sumr = c2r * 2 + c2l;
            if (suml > freel || sumr > freer) {
                continue;
            }
            ll cur1 = (1LL * dpl[sl - 1][c2l] * C(freel - c2l * 2, c2r)) % mod;
            ll cur2 = (1LL * dpr[sr - 1][c2r] * C(freer - c2r * 2, c2l)) % mod;
            ll res = (1LL * cur1 * cur2) % mod;
            res = (res * f[c2l]) % mod;
            res = (res * f[c2r]) % mod;
            ans += res;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}