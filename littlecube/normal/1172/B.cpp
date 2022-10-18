#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll f[200005], val[200005], pre[200005], n;
vector<int> e[200005];
ll fac(ll n)
{
    if (n <= 1)
        return 1;
    if (f[n] == 0)
        f[n] = (fac(n - 1) * n) % MOD2;
    return f[n];
}

void dfs(int n)
{
    val[n] = 1;
    for (int i : e[n])
        if (pre[n] != i)
        {
            pre[i] = n;
            dfs(i);
            val[n] = (val[n] * val[i]) % MOD2;
        }
    val[n] = (val[n] * fac(e[n].size())) % MOD2;
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].emplace_back(y), e[y].emplace_back(x);
    }
    dfs(1);
    cout << (val[1] * n) % MOD2 << '\n';
}