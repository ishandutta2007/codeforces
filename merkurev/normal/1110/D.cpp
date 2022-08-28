#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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



const int N = (int) 1e6 + 100;
int cnt[N];

int dp[N][3][3];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    int ans = 0;
    dp[0][0][0] = 0;
    for (int i = 0; i < (N - 5); i++)
    {
        for (int a = 0; a <= 2; a++)
            for (int b = 0; b <= 2; b++)
            {
                int cur = dp[i][a][b];
                for (int c = 0; c <= 2; c++)
                {
                    if (a + b + c > cnt[i] || b + c > cnt[i + 1] || c > cnt[i + 2])
                        continue;
                    int ndp = cur + c + (cnt[i] - a - b - c) / 3;
                    ans = max(ans, ndp);
                    dp[i + 1][b][c] = max(dp[i + 1][b][c], ndp);
                }
            }
    }
    printf("%d\n", ans);


	return 0;
}