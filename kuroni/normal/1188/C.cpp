#include <bits/stdc++.h>
using namespace std;

const int N = 1005, K = 1005, MX = 1E5, MOD = 998244353;

int n, k, ans = 0, a[N], f[N][K], g[MX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; i++)
        f[i][0] = 1;
    for (int lim = 1; lim <= MX / (k - 1); lim++)
    {
        int pt = 1;
        for (int i = 1; i <= n; i++)
        {
            while (a[i] - a[pt] >= lim)
                pt++;
            for (int j = 1; j <= i && j <= k; j++)
                f[i][j] = (f[i - 1][j] + f[pt - 1][j - 1]) % MOD;
        }
        g[lim] = f[n][k];
    }
    for (int i = MX / (k - 1); i >= 0; i--)
        (ans += 1LL * i * (g[i] - g[i + 1]) % MOD) %= MOD;
    cout << (ans + MOD) % MOD;
}