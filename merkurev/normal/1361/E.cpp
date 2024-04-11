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
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int) 1e5 + 100;

vector <int> g[N], rg[N];
int tin[N], tout[N];
int timer = 1;
bool bad[N];

void clearTimes(int n)
{
    for (int i = 0; i < n; i++)
    {
        tin[i] = 0;
        tout[i] = 0;
    }
    timer = 1;
}

bool dfs(int v)
{
    tin[v] = timer++;
    for (int to : g[v])
    {
        if (tin[to] == 0)
        {
            if (!dfs(to))
                return false;
        }
        else if (tout[to] != 0)
            return false;
    }
    tout[v] = timer;
    return true;
}

int solve1(int v)
{
    int cntUp = 0;
    tin[v] = timer++;
    for (int to : g[v])
    {
        if (tin[to] == 0)
            cntUp += solve1(to);
        else
            cntUp++;
    }
    cntUp -= (int) rg[v].size() - 1;
    if (cntUp >= 2)
        bad[v] = true;
    return cntUp;
}

int tv[N];
int xv[N];

int solve2(int v)
{
    int xUp = N;
    tv[timer] = v;
    tin[v] = timer++;
    for (int to : g[v])
    {
        if (tin[to] == 0)
            xUp = min(xUp, solve2(to));
        else
            xUp = min(xUp, tin[to]);
    }
    xv[v] = xUp;
    //if (xUp < tin[v] && bad[tv[xUp]])
    //    bad[v] = true;
    return xUp;
}

void solve(int n, int v)
{
    clearTimes(n);
    for (int i = 0; i < n; i++)
        bad[i] = false;

    solve1(v);

    clearTimes(n);

    solve2(v);

    for (int i = 1; i <= timer; i++)
    {
        int vv = tv[i];
        int xUp = xv[vv];
        if (xUp < tin[vv] && bad[tv[xUp]])
            bad[vv] = true;
    }
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        rg[i].clear();
        g[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    int s = -1;
    for (int i = 0; i < 100; i++)
    {
        int v = (rng() % n + n) % n;
        clearTimes(n);
        if (dfs(v))
        {
            s = v;
            break;
        }
    }
    if (s == -1)
    {
        printf("-1\n");
        return;
    }
    solve(n, s);

    vector <int> ans;
    for (int i = 0; i < n; i++)
        if (!bad[i])
            ans.push_back(i);

    if ((int) ans.size() * 5 < n)
    {
        printf("-1\n");
        return;
    }
    for (int x : ans)
        printf("%d ", x + 1);
    printf("\n");
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
    {
        solve();
    }

	return 0;
}