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


const int N = 1005;
int vals[4] = {1, 5, 10, 50};
bool dp[N * 50 + 1];

int solve(int n)
{
    memset(dp, 0, sizeof dp);
    for (int a = 0; a <= n; a++)
        for (int b = 0; a + b <= n; b++)
            for (int c = 0; a + b + c <= n; c++)
            {
                int d = n - a - b - c;
                int x = a + 5 * b + 10 * c + 50 * d;
                dp[x] = true;
            }
    int ans = 0;
    int mn = 50 * n;
    for (int i = 0; i <= 50 * n; i++)
    {
        if (i >= 25 * n && !dp[i]) mn = min(mn, i);
//        eprintf("%d", dp[i] );
        if (dp[i] ) ans++;
    }
//    eprintf("\n mn = %d\n", mn);

    return ans;
}

long long fastSolve(long long n)
{
    if (n <= 100) return solve(n);
    long long ans = solve(100);
    ans += 50 * n - 50 * 100 - (n - 100);// - 50 * (n - 100);
    return ans;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int n;
    scanf("%d", &n);
    printf("%lld\n", fastSolve(n));

	return 0;
}