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
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

const int N = 205;
char str[N];
int f[N][N][N];
int g[N][N];    
bool used[N];
int n;


bool dfs(int v, int par)
{
    //eprintf("dfs %d (from %d)\n", v, par);
    if (used[v])
        return false;
    g[v][par] = g[par][v] = 1;
    used[v] = true;
    for (int i = 0; i < n; i++)
    {
        //eprintf("%d %d %d : %d\n", i, par, v, f[i][par][v]);
        if (i != par && f[i][par][v])
            if (!dfs(i, v))
                return false;
    }
    return true;
}

bool solve(int a)
{
    //eprintf("======= solve %d =======\n", a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            g[i][j] = N;
        g[i][i] = 0;
    }
    for (int i = 0; i < n; i++)
        used[i] = false;

    if (!dfs(0, a))
        return false;
    if (!dfs(a, 0))
        return false;

    for (int i = 0; i < n; i++)
        if (!used[i])
            return false;

    for (int h = 0; h < n; h++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][h] + g[h][j]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int h = 0; h < n; h++)
                if (f[i][j][h] != (g[i][h] == g[j][h]))
                {
      //              eprintf("%d %d %d : %d != (%d == %d)\n", i, j, h, f[i][j][h], g[i][h], g[j][h]);
                    return false;
                }
    return true;
}


void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 1; i + j < n; j++)
        {
            scanf("%s", str);
            for (int k = 0; k < n; k++)
            {
                f[i][i + j][k] = f[i + j][i][k] = (str[k] - '0');
       //         eprintf("%d %d %d | %d\n", i, i + j, k, f[i][i + j][k]);
            }
        }

    for (int a = 1; a < n; a++)
    {
        if (solve(a))
        {
            printf("Yes\n");
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++)
                    if (g[i][j] == 1)
                        printf("%d %d\n", i + 1, j + 1);
            return;
        }
    }
    printf("No\n");
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