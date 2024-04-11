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

const long long INF = (long long)1e18;
const int N = 333;
long long dp[N][N];
vector<int> g[N], c[N];
int n, m, k;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int l, r, cc;
        cin >> l >> r >> cc;
        g[r].push_back(l - 1);
        c[r].push_back(cc);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = INF;
    for (int i = 0; i < N; i++)
        dp[i][0] = 0;
    for (int pos = 1; pos <= n; pos++)
    {
        for (int pk = 0; pk < N; pk++)
            dp[pos][pk] = dp[pos - 1][pk];
        for (int pk = 0; pk < N; pk++)
        {
            for (int i = 0; i < g[pos].size(); i++)
            {
                int to = g[pos][i];
                long long w = c[pos][i];
                dp[pos][min(N - 1, pk + pos - to)] = min(dp[pos][min(N - 1, pk + pos - to)], dp[to][pk] + w);
            }
        }
        for (int pk = 0; pk < N; pk++)
            for (int j = 0; j < pos; j++)
            {
                int f = pk - pos + j;
                if (f > 0)
                    dp[j][f] = min(dp[j][f], dp[pos][pk]);
            }
        for (int j = 0; j <= pos; j++)
            for (int pk = N - 2; pk >= 0; --pk)
                dp[j][pk] = min(dp[j][pk], dp[j][pk + 1]);
    }


    long long res = INF;
    for (int i = 0; i < N; i++)
        res = min(res, dp[i][k]);
    if (res == INF)
        cout << -1;
    else
        cout << res;


    return 0;
}