#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 5005;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int mult = 31;

int n;
char s[maxn];
int dp[maxn][maxn], p[maxn][maxn];
int h1[maxn], h2[maxn], pw1[maxn], pw2[maxn];

bool check(int a, int b, int k) {
    if (ll((h1[a+k+1] - h1[a] + mod) % mod) * pw1[b - a] % mod != (h1[b+k+1] - h1[b] + mod) % mod) return 0;
    if (ll((h2[a+k+1] - h2[a] + mod2) % mod2) * pw2[b - a] % mod2 != (h2[b+k+1] - h2[b] + mod2) % mod2) return 0;
    return 1;
}

bool cmp(int a, int b) {
    int lo = 0, hi = b - a;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (!check(a, b, mid)) hi = mid;
        else lo = mid + 1;
    }

    if (lo == b - a) return 0;
    return s[a+lo] < s[b+lo];
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> s;

    pw1[0] = pw2[0] = 1;
    for (int i = 0; i < n; i++) {
        pw1[i + 1] = ll(pw1[i]) * mult % mod;
        pw2[i + 1] = ll(pw2[i]) * mult % mod2;
        h1[i + 1] = (h1[i] + ll(pw1[i]) * s[i] % mod) % mod;
        h2[i + 1] = (h2[i] + ll(pw2[i]) * s[i] % mod2) % mod2;
    }

    dp[0][0] = p[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[j] == '0') dp[i][j] = 0;
            else {
                dp[i][j] = p[j][max(0, 2*j-i+1)];
                if (2*j-i >= 0 && cmp(2*j-i, j))
                    dp[i][j] = (dp[i][j] + dp[j][2*j-i]) % mod;
            }
        }

        for (int j = i - 1; j >= 0; j--)
            p[i][j] = (p[i][j+1] + dp[i][j]) % mod;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = (ans + dp[n][i]) % mod;
    cout << ans << '\n';
}