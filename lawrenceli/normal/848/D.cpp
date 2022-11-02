#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

//dpa[n, m] = sum (m1 >= m) dp[n, m1]
int dp[55][55], dpa[55][55], d2[55][55];
int d3[55];
int invn[55];

int exp(int b, int e) {
    if (!e) return 1;
    if (e & 1) return ll(exp(b, e - 1)) * b % mod;
    int res = exp(b, e >> 1);
    return ll(res) * res % mod;
}

void add(int& a, int b) { a = (a + b) % mod; }

int main() {
    for (int i = 1; i < 55; i++) invn[i] = exp(i, mod - 2);

    dp[0][0] = dpa[0][0] = 1;
    for (int n = 1; n <= 50; n++) {
        for (int m = 1; m <= 50; m++) {
            for (int n1 = 0; n1 < n; n1++) {
                int n2 = n - 1 - n1;
                add(d2[n][m], ll(dp[n1][m - 1]) * dpa[n2][m] % mod);
                add(d2[n][m], ll(dpa[n1][m]) * dp[n2][m - 1] % mod);
                add(d2[n][m], ll(dp[n1][m - 1]) * dp[n2][m - 1] % mod);
            }

            int cur = 1;
            int km = min(50 / n, 50 / m);
            for (int k = 1; k <= km; k++) {
                cur = ll(cur) * (d2[n][m] + k - 1) % mod * invn[k] % mod;
                d3[k] = cur;
            }

            for (int n1 = 50; n1 >= 0; n1--)
                for (int m1 = 50; m1 >= 0; m1--)
                    for (int k = 1; k <= km; k++) {
                        int n2 = n1 + n * k, m2 = m1 + m * k;
                        if (n2 <= 50 && m2 <= 50) add(dp[n2][m2], ll(dp[n1][m1]) * d3[k] % mod);
                    }
        }

        for (int m = 50; m >= 0; m--) dpa[n][m] = (dpa[n][m + 1] + dp[n][m]) % mod;
    }

    int n, m;
    cin >> n >> m;
    cout << dp[n][m - 1] << '\n';
}