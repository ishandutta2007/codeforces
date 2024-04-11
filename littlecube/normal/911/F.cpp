/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
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
using namespace __gnu_pbds;

#define LOCAL

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

int N, dis[200005], pre[200005], isdia[200005], val[200005];
ll ans;
vector<pii> sol;
vector<int> E[200005];

void dfs(int k)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dis[i] = dis[k] + 1;
            dfs(i);
        }
}

void dfs2(int k, int u, int v)
{
    for (int i : E[k])
        if (i != pre[k])
        {
            pre[i] = k;
            dfs2(i, u, v);
        }
    if (!isdia[k])
    {
        if (val[k] < dis[k])
        {
            ans += dis[k];
            sol.emplace_back(pii{v, k});
        }
        else
        {
            ans += val[k];
            sol.emplace_back(pii{u, k});
        }
    }
}

signed main()
{
    //fast;
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= N; i++)
        pre[i] = 0;
    dis[1] = 0;
    dfs(1);
    int u = 1, v = 1;
    for (int i = 1; i <= N; i++)
        if (dis[u] < dis[i])
            u = i;
    for (int i = 1; i <= N; i++)
        pre[i] = 0;
    dis[u] = 0;
    dfs(u);
    for (int i = 1; i <= N; i++)
        if (dis[v] < dis[i])
            v = i;
    int dia = v;
    isdia[u] = 1;
    while (dia != u)
    {
        isdia[dia] = 1;
        ans += dis[dia];
        dia = pre[dia];
    }
    for (int i = 1; i <= N; i++)
        val[i] = dis[i];
    for (int i = 1; i <= N; i++)
        pre[i] = 0;
    dis[v] = 0;
    dfs(v);
    for (int i = 1; i <= N; i++)
        pre[i] = 0;
    dfs2(u, u, v);
    dia = v;
    while (dia != u)
    {
        sol.emplace_back(pii{u, dia});
        dia = pre[dia];
    }
    cout << ans << '\n';
    for (pii p : sol)
        cout << p.F << " " << p.S << " " << p.S << '\n';
}