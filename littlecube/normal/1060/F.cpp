/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n, pre[55], sz[55];
double fac[55];
vector<int> E[55];
vector<double> dp[55];
// dp[u][k]: the probability of survival of node u, which we have already shrinked k times with u surviving.

double C(int n, int k)
{
    return fac[n] / fac[k] / fac[n - k];
}

void dfs(int u)
{
    sz[u] = 1;
    dp[u] = {1.0};
    for (auto c : E[u])
        if (c != pre[u])
        {
            pre[c] = u;
            dfs(c);

            vector<double> add(sz[c] + 1);
            for (int i = 0; i <= sz[c]; i++)
                for (int pos = 1; pos <= sz[c]; pos++)
                    if (pos <= i)
                        add[i] += dp[c][i - 1] / sz[c];
                    else
                        add[i] += dp[c][pos - 1] / sz[c] / 2;
            add.swap(dp[c]);

            vector<double> nxt(sz[c] + sz[u]);
            for (int i = 0; i <= sz[c]; i++)
                for (int j = 0; j < sz[u]; j++)
                    nxt[i + j] += dp[c][i] * C(sz[c], i) * dp[u][j] * C(sz[u] - 1, j) / C(sz[u] + sz[c] - 1, i + j);
            dp[u].swap(nxt);
            sz[u] += sz[c];
        }
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    fac[0] = 1.0;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            pre[j] = 0, sz[j] = 0;
        dfs(i);
        cout << fixed << setprecision(10) << dp[i][0] << '\n';
    }
}