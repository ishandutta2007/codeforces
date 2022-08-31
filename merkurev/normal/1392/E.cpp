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


const int N = 30;
const long long MX = (long long) 1e16;

long long mn[N][N], mx[N][N];
long long f[N][N];

void updMn(long long &a, long long b)
{
    if (a == -1 || a > b)
        a = b;
}
void updMx(long long &a, long long b)
{
    if (a == -1 || a < b)
        a = b;
}

void genF(int n)
{
    memset(mn, -1, sizeof mn);
    memset(mx, -1, sizeof mx);

    mn[0][0] = mx[0][0] = 0;

    for (int sum = 0; sum < 2 * n - 2; sum++)
    {
        for (int i = 0; i <= sum && i < n; i++)
        {
            int j = sum - i;
            if (j >= n)
                continue;
            f[i][j] = 0;
            if (i > 0)
                f[i][j] = max(0LL, mx[i - 1][j + 1] + 1 - mn[i][j]);
            mn[i][j] += f[i][j];
            mx[i][j] += f[i][j];

            if (f[i][j] > MX)
                throw;
            eprintf("%d %d : %lld\n", i, j, f[i][j]);

            updMn(mn[i + 1][j], mn[i][j]);
            updMn(mn[i][j + 1], mn[i][j]);
            updMx(mx[i + 1][j], mx[i][j]);
            updMx(mx[i][j + 1], mx[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%lld ", f[i][j]);
        printf("\n");
    }
    fflush(stdout);
}


void solve(int n)
{
    vector <pair <int, int>> ans;

    long long val;
    scanf("%lld", &val);

    int x = n - 1, y = n - 1;

    ans.emplace_back(x, y);
    while (x + y)
    {
        val -= f[x][y];
        if (x && y && mn[x][y - 1] <= mx[x - 1][y])
            throw;
        if (x && val <= mx[x - 1][y])
            x--;
        else if (y && val >= mn[x][y - 1])
            y--;
        else throw;

        ans.emplace_back(x, y);
    }

    reverse(ans.begin(), ans.end());

    for (auto p : ans)
        printf("%d %d\n", p.first + 1, p.second + 1);
    fflush(stdout);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    genF(n);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
        solve(n);

	return 0;
}