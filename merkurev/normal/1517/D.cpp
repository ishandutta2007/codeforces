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


const int K = 22;
const int N = 505;
int hor[N][N];
int ver[N][N];
int ans[N][N][K];


const int INF = 1e9;

void upd(int &a, int b)
{
    a = min(a, b);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            scanf("%d", &hor[i][j]);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &ver[i][j]);

    memset(ans, -1, sizeof ans);
    if (k % 2 == 0)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int best = INF;
                if (i != 0)
                    best = min(best, ver[i - 1][j]);
                if (i != n - 1)
                    best = min(best, ver[i][j]);
                if (j != 0)
                    best = min(best, hor[i][j - 1]);
                if (j != m -1)
                    best = min(best, hor[i][j]);
                for (int h = 2; h <= k; h += 2)
                    ans[i][j][h] = best * h;
            }

        for (int h = 2; h < k; h += 2)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    int cur = ans[i][j][h];
                    if (i != 0)
                        upd(ans[i - 1][j][h + 2], cur + 2 * ver[i - 1][j]);
                    if (i != n - 1)
                        upd(ans[i + 1][j][h + 2], cur + 2 * ver[i][j]);
                    if (j != 0)
                        upd(ans[i][j - 1][h + 2], cur + 2 * hor[i][j - 1]);
                    if (j != m - 1)
                        upd(ans[i][j + 1][h + 2], cur + 2 * hor[i][j]);
                }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", ans[i][j][k]);
        printf("\n");
    }


	return 0;
}