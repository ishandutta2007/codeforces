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
//using namespace __gnu_pbds;

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

ll N, s, dp[2005][2], tdp[2005][2], arr[2005], order[2005], M = 1;
vector<int> v[2005], pathdp[2005][2];

void dfs(int pos, int i)
{
    if (pos == 0)
        return;
    dfs(tdp[pos][i], i ^ 1);
    //cout << pos << " " << i << '\n';
    for (int i : pathdp[pos][i])
    {
        if (i >= 0)
            cout << "+" << i << '\n';
        else
            cout << i << '\n';
    }
}

int dis(int a, int b)
{
    if (abs(b - a) <= abs(b - (a + N)) && abs(b - a) <= abs(b - a + N))
        return b - a;
    if (abs(b - (a + N)) <= abs(b - a) && abs(b - (a + N)) <= abs(b - a + N))
        return b - (a + N);
    return b - a + N;
}

signed main()
{
    fast;
    cin >> N >> s;
    for (int i = 1; i <= N; i++)
        cin >> arr[i], order[i] = i;
    sort(order + 1, order + N + 1, [=](int a, int b)
         {
             if (arr[a] != arr[b])
                 return arr[a] < arr[b];
             return a < b;
         });

    v[M].pb(order[1]);
    for (int i = 2; i <= N; i++)
        if (arr[order[i]] == arr[order[i - 1]])
            v[M].pb(order[i]);
        else
            v[++M].pb(order[i]);

    for (int i = 1; i <= N; i++)
        dp[i][0] = dp[i][1] = 1e18;
    for (int i = 1; i <= M; i++)
    {
        if (i == 1)
            for (int j : v[1])
            {
                dp[j][0] = abs(dis(s, j));
                pathdp[j][0].pb(dis(s, j));
            }
        else
            for (int j : v[i])
                for (int k : v[i - 1])
                    if (dp[j][0] > dp[k][1] + abs(dis(k, j)))
                    {
                        dp[j][0] = dp[k][1] + abs(dis(k, j));
                        tdp[j][0] = k;
                        pathdp[j][0].clear();
                        pathdp[j][0].pb(dis(k, j));
                    }
        if (v[i].size() != 1)
            for (int j = 0; j < v[i].size(); j++)
            {
                int prev = (j + v[i].size() - 1) % v[i].size(),
                    next = (j + 1) % v[i].size();
                if (N - abs((v[i][j] + N - v[i][prev]) % N) + dp[v[i][prev]][0] < N - abs((v[i][j] - v[i][next] - N) % N) + dp[v[i][next]][0])
                {
                    dp[v[i][j]][1] = N - abs((v[i][j] + N - v[i][prev]) % N) + dp[v[i][prev]][0];
                    //cout << v[i][j] << " clockwise\n";
                    for (int k = prev; k != j; k = (k - 1 + v[i].size()) % v[i].size())
                        pathdp[v[i][j]][1].pb(-abs((v[i][k] + N - v[i][(k - 1 + v[i].size()) % v[i].size()]) % N));

                    tdp[v[i][j]][1] = v[i][prev];
                }
                else
                {
                    dp[v[i][j]][1] = N - abs((v[i][j] - v[i][next] - N) % N) + dp[v[i][next]][0];
                    for (int k = next; k != j; k = (k + 1) % v[i].size())
                        pathdp[v[i][j]][1].pb(abs((v[i][(k + 1) % v[i].size()] + N - v[i][k]) % N));
                    tdp[v[i][j]][1] = v[i][next];
                }
            }
        else
        {
            dp[v[i][0]][1] = dp[v[i][0]][0];
            tdp[v[i][0]][1] = v[i][0];
        }
    }
    int ans = 1000000000000000000, pos;
    for (int i : v[M])
        if (dp[i][1] < ans)
            ans = dp[i][1], pos = i;
    cout << ans << '\n';
    dfs(pos, 1);
}