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

const int INF = (int) 1e9 + 100;
int dp[2][4];

const int N = (int) 1e5 + 100;
char str[N];

void upd(int &a, int b)
{
    a = min(a, b);
}

void solve()
{
    scanf("%s", str);
    int n = strlen(str);

    int t = 0, nt = 1;
    memset(dp, 0, sizeof dp);
    for (int j = 0; j < 4; j++)
        dp[t][j] = INF;
    dp[0][3] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            dp[nt][j] = INF;
        for (int mask = 0; mask < 4; mask++)
        {
            int cur = dp[t][mask];
            if (cur == INF)
                continue;
            int am = mask & 1;
            int bm = (mask >> 1) & 1;
            upd(dp[nt][bm | 2], cur + 1);
            if ((am || str[i] != str[i - 2]) && (bm || str[i] != str[i - 1]))
                upd(dp[nt][bm], cur);
        }
        swap(t, nt);
    }
    int ans = INF;
    for (int j = 0; j < 4; j++)
        ans = min(ans, dp[t][j]);
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