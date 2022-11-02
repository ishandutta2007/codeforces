#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

const int N = 55;
const int INF = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
int ways[N][N][N][2];
int dp[N][N][N][2];
int cnt100 = 0;
int cnt50 = 0;
int n, k;
queue<int> fls;
queue<int> flb;
queue<int> frs;
queue<int> lr;
long long c[N][N];

void init()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            c[i][j] = 0;
        }
    c[0][0] = 1;
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            if (j == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
}

void solve()
{
    init();

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int w;
        cin >> w;
        if (w == 50)
            ++cnt50;
        else
            ++cnt100;
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int t = 0; t < N; ++t)
            {
                ways[i][j][t][0] = ways[i][j][t][1] = 0;
                dp[i][j][t][0] = dp[i][j][t][1] = INF;
            }
    dp[cnt50][cnt100][0][0] = 0;
    ways[cnt50][cnt100][0][0] = 1;
    fls.push(cnt50);
    flb.push(cnt100);
    frs.push(0);
    lr.push(0);
    while (!fls.empty())
    {
        int vfls = fls.front();
        fls.pop();
        int vflb = flb.front();
        flb.pop();
        int vfrs = frs.front();
        frs.pop();
        int vlr = lr.front();
        lr.pop();
        int vfrb = n - vfls - vflb - vfrs;
        if (vlr == 0)
        {
            for (int k1 = 0; k1 <= vfls; ++k1)
                for (int k2 = 0; k2 <= vflb; ++k2)
                {
                    if (k1 == 0 && k2 == 0)
                        continue;
                    if (k1 * 50 + k2 * 100 > k)
                        continue;
                    if (dp[vfls - k1][vflb - k2][vfrs + k1][1] == dp[vfls][vflb][vfrs][0] + 1)
                    {
                        ways[vfls - k1][vflb - k2][vfrs + k1][1] += ways[vfls][vflb][vfrs][0] * c[vfls][k1] % mod * c[vflb][k2] % mod;
                        ways[vfls - k1][vflb - k2][vfrs + k1][1] %= mod;
                    }
                    if (dp[vfls - k1][vflb - k2][vfrs + k1][1] > dp[vfls][vflb][vfrs][0] + 1)
                    {
                        dp[vfls - k1][vflb - k2][vfrs + k1][1] = dp[vfls][vflb][vfrs][0] + 1;
                        fls.push(vfls - k1);
                        flb.push(vflb - k2);
                        frs.push(vfrs + k1);
                        lr.push(1);
                        ways[vfls - k1][vflb - k2][vfrs + k1][1] = ways[vfls][vflb][vfrs][0] * c[vfls][k1] % mod * c[vflb][k2] % mod;
                    }
                }
        }
        else
        {
            for (int k1 = 0; k1 <= vfrs; ++k1)
                for (int k2 = 0; k2 <= vfrb; ++k2)
                {
                    if (k1 == 0 && k2 == 0)
                        continue;
                    if (k1 * 50 + k2 * 100 > k)
                        continue;
                    if (dp[vfls + k1][vflb + k2][vfrs - k1][0] == dp[vfls][vflb][vfrs][1] + 1)
                    {
                        ways[vfls + k1][vflb + k2][vfrs - k1][0] += ways[vfls][vflb][vfrs][1] * c[vfrs][k1] % mod * c[vfrb][k2] % mod;
                        ways[vfls + k1][vflb + k2][vfrs - k1][0] %= mod;
                    }
                    if (dp[vfls + k1][vflb + k2][vfrs - k1][0] > dp[vfls][vflb][vfrs][1] + 1)
                    {
                        dp[vfls + k1][vflb + k2][vfrs - k1][0] = dp[vfls][vflb][vfrs][1] + 1;
                        fls.push(vfls + k1);
                        flb.push(vflb + k2);
                        frs.push(vfrs - k1);
                        lr.push(0);
                        ways[vfls + k1][vflb + k2][vfrs - k1][0] = ways[vfls][vflb][vfrs][1] * c[vfrs][k1] % mod * c[vfrb][k2] % mod;
                    }
                }
        }
    }

    if (dp[0][0][cnt50][1] == INF)
    {
        cout << -1 << endl;
        cout << 0 << endl;
    }
    else
    {
        cout << dp[0][0][cnt50][1] << endl;
        cout << ways[0][0][cnt50][1] << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}