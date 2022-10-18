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

ll N, M, K, mp[1005][1005], vis[1000][1000], res[1000][1000], ans;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (mp[x + 1][y] == 0 && vis[x + 1][y] == 0)
        dfs(x + 1, y);
    else if (mp[x + 1][y] == 1)
        ans++;

    if (mp[x - 1][y] == 0 && vis[x - 1][y] == 0)
        dfs(x - 1, y);
    else if (mp[x - 1][y] == 1)
        ans++;

    if (mp[x][y + 1] == 0 && vis[x][y + 1] == 0)
        dfs(x, y + 1);
    else if (mp[x][y + 1] == 1)
        ans++;

    if (mp[x][y - 1] == 0 && vis[x][y - 1] == 0)
        dfs(x, y - 1);
    else if (mp[x][y - 1] == 1)
        ans++;
}


void dfs2(int x, int y)
{
    vis[x][y] = 2;
    res[x][y] = ans;
    if (mp[x + 1][y] == 0 && vis[x + 1][y] == 1)
        dfs2(x + 1, y);

    if (mp[x - 1][y] == 0 && vis[x - 1][y] == 1)
        dfs2(x - 1, y);

    if (mp[x][y + 1] == 0 && vis[x][y + 1] == 1)
        dfs2(x, y + 1);

    if (mp[x][y - 1] == 0 && vis[x][y - 1] == 1)
        dfs2(x, y - 1);
}

signed main()
{
    fast;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            char c;
            cin >> c;
            mp[i][j] = (c == '*' ? 1 : 0);
        }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (mp[i][j] == 0 && vis[i][j] == 0)
            {
                ans = 0;
                dfs(i, j);
                dfs2(i, j);
            }
    for (int i = 1; i <= K; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << res[x][y] << '\n';
    }
}