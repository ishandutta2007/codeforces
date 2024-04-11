#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxp = 61;
const int Maxk = 10005;

int inv[Maxp];
int dp[Maxp][Maxk];
ll n;
int k;
int res = 1;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int Solve(int pr, int has, int k)
{
    for (int i = 0; i <= has; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 0;
    dp[has][k] = 1;
    for (int i = has; i >= 0; i--)
        for (int j = k; j > 0; j--) if (dp[i][j]) {
            int give = ll(dp[i][j]) * inv[i + 1] % mod;
            for (int z = 0; z <= i; z++)
                dp[z][j - 1] = (dp[z][j - 1] + give) % mod;
        }
    int res = 0, cur = 1;
    for (int i = 0; i <= has; i++) {
        res = (res + ll(cur) * dp[i][0]) % mod;
        cur = ll(cur) * pr % mod;
    }
    return res;
}

int main()
{
    for (int i = 1; i < Maxp; i++)
        inv[i] = Inv(i);
    cin >> n >> k;
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
        int cnt = 0;
        while (n % i == 0) { n /= i; cnt++; }
        res = ll(res) * Solve(i % mod, cnt, k) % mod;
    }
    if (n > 1) res = ll(res) * Solve(n % mod, 1, k) % mod;
    printf("%d\n", res);
    return 0;
}