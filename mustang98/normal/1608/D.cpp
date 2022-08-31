#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222, mod = 998244353;
int f[max_n];
int rf[max_n];

int powm(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return powm((1LL * a * a) % mod, b / 2);
    } else {
        return (1LL * a * powm(a, b - 1)) % mod;
    }
}

void precalc() {
    f[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % mod;
    }
    rf[max_n - 1] = powm(f[max_n - 1], mod - 2);
    for (int i = max_n - 2; i >= 0; --i) {
        rf[i] = (1LL * rf[i + 1] * (i + 1)) % mod;
    }

}

int C(int n, int k) {
    if (k > n) return 0;
    return ((1LL * f[n] * rf[n - k] % mod) * rf[k]) % mod;
}

int A(int n, int k) {
    if (k > n) return 0;
    return (1LL * f[n] * rf[n - k]) % mod;
}

string s[max_n];
int n;
ll dp[max_n][4];

bool can01(string s) {
    if (s[0] == '1') return 0;
    if (s[1] == '0') return 0;
    return 1;
}
bool can10(string s) {
    if (s[0] == '0') return 0;
    if (s[1] == '1') return 0;
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    precalc();
    int c1 =0, c0 = 0, cq = 0;
    bool have00 = 0;
    bool have11 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < 2; ++j) {
            if (s[i][j] == 'W') s[i][j] = '0';
            if (s[i][j] == 'B') s[i][j] = '1';
            if (s[i][j] == '0') ++c0;
            if (s[i][j] == '1') ++c1;
            if (s[i][j] == '?') ++cq;
        }
        if (s[i] == "00") have00 = 1;
        if (s[i] == "11") have11 = 1;
    }
    if (c0 > n || c1 > n) {
        puts("0");
        return 0;
    }
    int need = n - c0;
    ll ans = C(cq, need);
    if (have00 || have11) {
        cout << ans << endl;
        return 0;
    }
    c0 = can01(s[0]);
    c1 = can10(s[0]);
    if (c0) {
        dp[0][1] = 1;
    }
    if (c1) {
        dp[0][2] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int c0 = can01(s[i]);
        int c1 = can10(s[i]);
        for (int mask = 0; mask <= 3; ++mask) {
            if (c0) {
                dp[i][mask | 1] += dp[i - 1][mask];
                dp[i][mask | 1] %= mod;
            }
            if (c1) {
                dp[i][mask | 2] += dp[i -1][mask];
                dp[i][mask | 2] %= mod;
            }
        }
    }
    //cout << ans << endl;
    cout << (ans - dp[n - 1][3] + mod) % mod;
    return 0;
}