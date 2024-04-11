/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
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

int N, A, B, deg[200005], vis[200005], dis[200005], ans = 1000000;

vector<int> e[200005];

void dfs(int k)
{
    vis[k] = 1;
    for (int i : e[k])
        if (!vis[i])
        {
            dis[i] = dis[k] + 1;
            dfs(i);
        }
}
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int random()
{
    return rd() % N + 1;
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> A >> B;
        e[A].pb(B);
        e[B].pb(A);
    }

    int res = -1, res2 = -1;
    dis[1] = 0;
    dfs(1);
    for (int i = 1; i <= N; i++)
        if (dis[i] % 2)
            res++;
        else
            res2++;
    cout << min({res, res2, ans});
}