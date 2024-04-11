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


const int N = (int) 2e5 + 100;
char str[N];

const int INF = (int) 1e9 + 100;

int dp[N][2][2][2][2];


void upd(int &a, int b)
{
    a = min(a, b);
}

int a[N];

void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", str);

    for (int i = 0; i < n; i++)
        a[i] = (str[i] == 'L');

    for (int p = 0; p <= n; p++)
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int ii = 0; ii < 2; ii++)
                    for (int jj = 0; jj < 2; jj++)
                        dp[p][i][j][ii][jj] = INF;


    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
        {
            dp[0][i][j][i][j] = 0;//(a[n - 2] != i) + (a[n - 1] != j);
        }

    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
                for (int ii = 0; ii < 2; ii++)
                    for (int jj = 0; jj < 2; jj++)
                        for (int c = 0; c < 2; c++)
                        {
                            int ncost = dp[i][x][y][ii][jj] + (a[i] != c);
                            if (ii == 1 && c == 1 && jj == 1)
                                continue;
                            if (ii == 0 && c == 0 && jj == 0)
                                continue;
                            upd(dp[i + 1][x][y][jj][c], ncost);
                        }
    }
    int ans = INF;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            upd(ans, dp[n][i][j][i][j]);
    printf("%d\n", ans);
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