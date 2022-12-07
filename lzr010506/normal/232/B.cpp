#include <bits/stdc++.h>
#define eps 1e-8
#define ll long long
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair
#define mod (1000000007ll)

using namespace std;

ll cheng (ll v, ll d)
{
    if (d == 0) return 1;
    if (d & 1ll) return (v * cheng(v, d - 1)) % mod;
    return cheng((v * v) % mod, d / 2);
}

ll C[110][110], f[110][110];
ll Ans[11000], As[11000];

int main()
{
    int n, k, i, j, l;
    ll m;
    cin >> n >> m >> k;
    for (int i = 0; i < 110; i ++)
        for (C[i][0] = 1ll, j = 1; j <= i; j ++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j <= n;  j++)
            f[i][j] = cheng(C[n][j], (m + n - 1ll - i) / ((ll)n));
    Ans[0] = 1ll;
    for (int i = 0; i < n; i ++)
    {
        for (int j = max(0, k - (n - i) * n); j <= k; j ++)
            for (int l = 0; l <= n; l ++)
                As[j + l] += f[i][l] * Ans[j], As[j + l] %= mod;
        memcpy(Ans, As, sizeof(Ans));
        memset(As, 0, sizeof(As));
    }
    cout << Ans[k] << endl;
    return 0;
}