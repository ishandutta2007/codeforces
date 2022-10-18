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
//#define int long long
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

int N, T, M;

bool solve()
{
    int g[305][305] = {{0}};

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> g[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if(g[i][j] > 4)
                return 0;
    for (int i = 1; i <= N; i++)
        if (g[i][1] > 3)
            return 0;
    for (int i = 1; i <= N; i++)
        if (g[i][M] > 3)
            return 0;
    for (int i = 1; i <= M; i++)
        if (g[1][i] > 3)
            return 0;
    for (int i = 1; i <= M; i++)
        if (g[N][i] > 3)
            return 0;
    if (g[1][1] > 2)
        return 0;
    if (g[N][1] > 2)
        return 0;
    if (g[1][M] > 2)
        return 0;
    if (g[N][M] > 2)
        return 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            g[i][j] = 4;
    for (int i = 1; i <= N; i++)
        g[i][1] = 3;
    for (int i = 1; i <= N; i++)
        g[i][M] = 3;
    for (int i = 1; i <= M; i++)
        g[1][i] = 3;
    for (int i = 1; i <= M; i++)
        g[N][i] = 3;
    g[1][1] = 2;
    g[N][1] = 2;
    g[1][M] = 2;
    g[N][M] = 2;
    cout << "YES\n";

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cout << g[i][j] << " \n"[j == M];
    return 1;
}

signed main()
{
    fast;
    cin >> T;
    while (cin >> N >> M)
        if (!solve())
            cout << "NO\n";
}