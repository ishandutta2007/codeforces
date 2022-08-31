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

const int N = (int) 1e5 + 100;
char f[2][N];

const int BASE = (int) 1e6;
int dp[2][4];

void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s%s", f[0], f[1]);

    int t = 0, nt = 1;
    memset(dp, 0, sizeof dp);

    dp[t][0] = BASE;

    for (int i = 0; i < n; i++)
    {
        int cur = ((1 << (int)(f[0][i] - '0')) | (1 << (int)(f[1][i] - '0')));
        memset(dp[nt], 0, sizeof dp[nt]);

        for (int j = 0; j < 4; j++)
        {
            int nj = (j | cur);
            dp[nt][nj] = max(dp[nt][nj], dp[t][j]);
        }

        dp[nt][0] = max(dp[nt][0], dp[nt][1] + 1);
        dp[nt][0] = max(dp[nt][0], dp[nt][3] + 2);
        dp[nt][0] = max(dp[nt][0], dp[nt][2]);

        swap(t, nt);
    }

    printf("%d\n", dp[t][0] - BASE);
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