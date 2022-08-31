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


const int N = 55;
double p[N];
int d[N], small[N], big[N];
const int MX = 100 * N;
long double dp[N][MX];
const int IT = 200;
int sum[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, r;
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++)
    {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        small[i] = a;
        big[i] = b;
        p[i] = ((double) k) / 100.;
        r -= a;
        d[i] = b - a;
        sum[i + 1] = sum[i] + d[i];
    }
    double lb = 0, rb = 1e30;
    
    for (int it = 0; it < IT; it++)
    {
        double mb = (lb + rb) / 2.;

        for (int i = 0; i <= r; i++)
            dp[n][i] = 0;
        for (int i = r + 1; i <= sum[n]; i++)
            dp[n][i] = mb;
        
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j <= sum[i]; j++)
            {
                long double a = p[i] * (small[i] + dp[i + 1][j] ) + (1. - p[i]) * (big[i] + dp[i + 1][j + d[i] ] );
                long double b = mb;
                dp[i][j] = min(a, b);
            }
        if (dp[0][0] < mb)
            rb = mb;
        else
            lb = mb;
    }
    printf("%.12lf\n", lb);

	return 0;
}