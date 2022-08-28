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


const int INF = (int) 1e9;
const int N = 55;
int a[N];
int dp[N][N];

int solve(int l, int r)
{
    if (r < l) return 0;
    if (dp[l][r] != -INF)
        return dp[l][r];
    int v1 = -solve(l + 1, r) + a[l];
    int v3 = solve(l + 1, r) - a[l];

    int ans = max({v1, v3});
    eprintf("solve(%d, %d) = %d\n", l, r, ans);
    return dp[l][r] = ans;
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -INF;

    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i] );
        sum += a[i];
    }
    int ba = solve(0, n - 1);
    int aa = (sum - ba) / 2;
    int b = sum - aa;

    printf("%d %d\n", aa, b);

	return 0;
}