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


const long long INF = (long long) 4e18;
const int N = (int) 1e5 + 100;
const int K = 3;
long long k[K];
long long dp[N][K + 2];
int a[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < K; i++)
        scanf("%lld", &k[i] );
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i] );

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= K; j++)
            dp[i][j] = -INF;

    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= K; j++)
        {
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + a[i] * k[j] );
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] );
        }
    printf("%lld\n", dp[n][K] );

	return 0;
}