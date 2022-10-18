#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pll> v;

int main()
{
    int n, m, b, mod, a[505], dp[505][505] = {{1}};
    cin >> n >> m >> b >> mod;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= b; k++)
                if (j + 1 <= m && k + a[i] <= b)
                    dp[j + 1][k + a[i]] = (dp[j][k] + dp[j + 1][k + a[i]]) % mod;

    ll r = 0;
    for (int k = 0; k <= b; k++)
        r = (r + dp[m][k]) % mod;

    cout << r << '\n';
}