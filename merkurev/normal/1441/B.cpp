#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int MOD = 998244353;

void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
 

const int N = (int) 2e5 + 100;
vector <int> g[2][N];

const int LOG = 20;
int dp[N][LOG];

priority_queue <pair <int, pair<int, int>>> qu;

void updateDp(int v, int sw, int val)
{
    if (dp[v][sw] == -1 || dp[v][sw] > val)
    {
        dp[v][sw] = val;
        qu.push(make_pair(-val, make_pair(v, sw)));
    }
}

pair <int, int> dpBig[2][N];

priority_queue <pair <pair <int, int>, pair <int, int>>> quBig;

void updateDpBig(int v, int sw, pair <int, int> val)
{
    if (dpBig[v][sw].first == -1 || dpBig[v][sw] > val)
    {
        dpBig[v][sw] = val;
        quBig.push(make_pair(make_pair(-val.first, -val.second), make_pair(v, sw)));
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[0][a].push_back(b);
        g[1][b].push_back(a);
    }

    memset(dp, -1, sizeof dp);
    updateDp(0, 0, 0);

    while (!qu.empty())
    {
        int cd = -qu.top().first;
        int v = qu.top().second.first;
        int sw = qu.top().second.second;
        qu.pop();
        if (dp[v][sw] != cd)
            continue;
        int t = sw % 2;
        if (sw + 1 < LOG)
            updateDp(v, sw + 1, cd);
        for (int to : g[t][v])
        {
            updateDp(to, sw, cd + 1);
        }
    }

    int ans = -1;
    for (int i = 0; i < LOG; i++)
    {
        int cur = dp[n - 1][i];
        if (cur == -1)
            continue;
        cur += (1 << i) - 1;
        if (ans == -1 || cur < ans)
            ans = cur;
    }

    if (ans != -1)
    {
        printf("%d\n", ans);
        return 0;
    }


    memset(dpBig, -1, sizeof dpBig);
    updateDpBig(0, 0, make_pair(0, 0));

    while (!quBig.empty())
    {
        pair <int, int> cd = quBig.top().first;
        cd = {-cd.first, -cd.second};
        int state = quBig.top().second.first;
        int v = quBig.top().second.second;
        quBig.pop();
        if (dpBig[state][v] != cd)
            continue;
        updateDpBig(state ^ 1, v, make_pair(cd.first + 1, cd.second));
        for (int to : g[state][v])
        {
            updateDpBig(state, to, make_pair(cd.first, cd.second + 1));
        }
    }

    if (dpBig[1][n - 1].first != -1)
        updateDpBig(0, n - 1, dpBig[1][n - 1]);

    eprintf("ans = (%d, %d)\n", dpBig[0][n - 1].first, dpBig[0][n - 1].second);

    ans = 1;
    for (int i = 0; i < dpBig[0][n - 1].first; i++)
        ans = mul(ans, 2);
    ssub(ans, 1);
    sadd(ans, dpBig[0][n - 1].second);

    printf("%d\n", ans);


	return 0;
}