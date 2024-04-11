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

const int K = 55;
int dp[K][K][2][2];

void init()
{
    for (int a = 0; a < K; a++)
        for (int b = 0; b < K; b++)
            for (int ca = 0; ca < 2; ca++)
                for (int cb = 0; cb < 2; cb++)
                {
                    int &cur = dp[a][b][ca][cb];
                    if (a == 0 && b == 0)
                    {
                        cur = (ca == 1);
                        continue;
                    }
                    if (a > 0 && !dp[a - 1][b][cb][ca ^ 1])
                        cur = 1;
                    if (b > 0 && !dp[a][b - 1][cb][ca])
                        cur = 1;
                }
    for (int a = 0; a < K; a++)
    {
        for (int b = 0; b < K; b++)
        {
            if (dp[a][b][0][0] != dp[a % 4][b % 2][0][0])
                throw;
            //eprintf("%d", dp[a][b][0][0]);
        }
        //eprintf("\n");
    }
}

const int LOG = 30;
const int N = (int) 1e5 + 100;

int a[N];

void solve(int ones, int zeros)
{
    if (dp[ones % 4][zeros % 2][0][0])
        printf("WIN\n");
    else
        printf("LOSE\n");
}

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = LOG; i >= 0; i--)
    {
        int ones = 0;
        for (int j = 0; j < n; j++)
            if (a[j] & (1 << i))
                ones++;
        if (ones % 2 == 1)
        {
            solve(ones, n - ones);
            return;
        }
    }
    printf("DRAW\n");
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    init();

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();


	return 0;
}