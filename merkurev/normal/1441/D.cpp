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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 2e5 + 100;
vector <int> g[N], ch[N];

int dp[N][2];
int color[N];

vector <int> chPref[N][2], chSuff[N][2];

void solveDown(int v)
{
    eprintf("solve down %d\n", v);
    dp[v][0] = dp[v][1] = 0;
    if (color[v] == 1)
        dp[v][1] = N;
    if (color[v] == 2)
        dp[v][0] = N;

    chPref[v][0].resize((int) ch[v].size() + 1);
    chPref[v][1].resize((int) ch[v].size() + 1);
    chSuff[v][0].resize((int) ch[v].size() + 1);
    chSuff[v][1].resize((int) ch[v].size() + 1);

    for (int to : ch[v])
        solveDown(to);

    chPref[v][0][0] = dp[v][0];
    chPref[v][1][0] = dp[v][1];
    for (int i = 0; i < (int) ch[v].size(); i++)
    {
        int to = ch[v][i];
        chPref[v][0][i + 1] = max(chPref[v][0][i], min(dp[to][0], dp[to][1] + 1));
        chPref[v][1][i + 1] = max(chPref[v][1][i], min(dp[to][1], dp[to][0] + 1));
    }
    chSuff[v][0].back() = dp[v][0];
    chSuff[v][1].back() = dp[v][1];
    for (int i = (int) ch[v].size() - 1; i >= 0; i--)
    {
        int to = ch[v][i];
        chSuff[v][0][i] = max(chSuff[v][0][i + 1], min(dp[to][0], dp[to][1] + 1));
        chSuff[v][1][i] = max(chSuff[v][1][i + 1], min(dp[to][1], dp[to][0] + 1));
    }

    dp[v][0] = chPref[v][0].back();
    dp[v][1] = chPref[v][1].back();
    eprintf("%d) %d %d\n", v, dp[v][0], dp[v][1]);
}

int ans;

void solveAll(int v, int up0, int up1)
{
    eprintf("solveAll %d %d %d\n", v, up0, up1);
    int cur0 = max(dp[v][0], min(up0, up1 + 1));
    int cur1 = max(dp[v][1], min(up1, up0 + 1));

    ans = min({ans, cur0, cur1});

    for (int i = 0; i < (int) ch[v].size(); i++)
    {
        int to = ch[v][i];
        
        int nup0 = max({chPref[v][0][i], chSuff[v][0][i + 1], min(up0, up1 + 1)});
        int nup1 = max({chPref[v][1][i], chSuff[v][1][i + 1], min(up1, up0 + 1)});
        solveAll(to, nup0, nup1);
    }
}

void dfs(int v, int par)
{
    eprintf("dfs %d %d\n", v, par);
    for (int to : g[v])
    {
        if (to == par)
            continue;
        ch[v].push_back(to);
        dfs(to, v);
    }
}

void solve()
{
    int n;
    scanf("%d", &n);

    ans = N;
    for (int i = 0; i < n; i++)
    {
        ch[i].clear();
        g[i].clear();
    }

    for (int i = 0; i < n; i++)
        scanf("%d", &color[i]);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, -1);
    solveDown(0);

    solveAll(0, 0, 0);

    printf("%d\n", ans + 1);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();


	return 0;
}