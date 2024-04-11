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


const int K = 105;
const int N = (int) 1e4 + 100;
int c[N];

long double dp[K][N];
long double C[K][K];
long double fact[K];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    fact[0] = 1;
    for (int i = 0; i < K; i++)
    {
        if (i != 0)
            fact[i] = fact[i - 1] * i;
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }


    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = i; j >= 0; j--)
            for (int s = 0; s + c[i] < N; s++)
            {
                dp[j + 1][s + c[i]] += dp[j][s];
            }

    long double ans = 0;
    for (int k = 1; k <= n; k++)
    {
        long double xx = x;
        xx += ((long double) n / (long double) k - 1.) * (long double) x / 2.;

        long double value = 0;
        for (int s = 0; s < N; s++)
        {
            long double cur = dp[k][s];
            if (cur < 0.5)
                continue;
            long double A = xx;
            long double B = (long double) s / (long double) k;

            value += cur * min(A, B);
        }
        value /= C[n][k];
        ans += value;
    }

    printf("%.14lf\n", (double) ans);


	return 0;
}