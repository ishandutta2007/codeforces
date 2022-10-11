#include <bits/stdc++.h>
using namespace std;

const int N = 100005, MOD = 1E9 + 7;

int n;
long long f[N][4];
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s >> t;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        char c = s[i - 1], d = t[i - 1];
        if (c != '?' && d != '?') {
            if (c == d) {
                f[i][0] = f[i - 1][0];
                f[i][1] = f[i - 1][1];
                f[i][2] = f[i - 1][2];
                f[i][3] = f[i - 1][3];
            } else if (c < d) {
                f[i][1] = (f[i - 1][0] + f[i - 1][1]) % MOD;
                f[i][3] = (f[i - 1][3] + f[i - 1][2]) % MOD;
            } else {
                f[i][2] = (f[i - 1][0] + f[i - 1][2]) % MOD;
                f[i][3] = (f[i - 1][3] + f[i - 1][1]) % MOD;
            }
        } else if (c == '?' && d != '?') {
            int v = d - '0';
            f[i][0] = f[i - 1][0];
            f[i][1] = (f[i - 1][0] * v + f[i - 1][1] * (v + 1)) % MOD;
            f[i][2] = (f[i - 1][0] * (9 - v) + f[i - 1][2] * (10 - v)) % MOD;
            f[i][3] = (f[i - 1][1] * (9 - v) + f[i - 1][2] * v + f[i - 1][3] * 10) % MOD;
        } else if (c != '?' && d == '?') {
            int v = c - '0';
            f[i][0] = f[i - 1][0];
            f[i][1] = (f[i - 1][0] * (9 - v) + f[i - 1][1] * (10 - v)) % MOD;
            f[i][2] = (f[i - 1][0] * v + f[i - 1][2] * (v + 1)) % MOD;
            f[i][3] = (f[i - 1][1] * v + f[i - 1][2] * (9 - v) + f[i - 1][3] * 10) % MOD;
        } else {
            f[i][0] = f[i - 1][0] * 10 % MOD;
            f[i][1] = (f[i - 1][0] * 45 + f[i - 1][1] * 55) % MOD;
            f[i][2] = (f[i - 1][0] * 45 + f[i - 1][2] * 55) % MOD;
            f[i][3] = (f[i - 1][1] * 45 + f[i - 1][2] * 45 + f[i - 1][3] * 100) % MOD;
        }
    }
    cout << f[n][3];
}