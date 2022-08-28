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


const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
int fpow(int x, int n)
{
    if (n == 0) return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1) a = mul(a, x);
    return a;
}
int frev(int x)
{
    return fpow(x, MOD - 2);
}
const int N = 5005;
int rev[N];
int dp[N][N];
int fact[N];

void init()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        rev[i] = frev(i);
    }

    dp[0][0] = 1;
    for (int i = 0; i + 1 < N; i++)
        for (int j = 0; j <= i; j++)
        {
            sadd(dp[i + 1][j + 1], dp[i][j] );
            sadd(dp[i + 1][j], mul(dp[i][j], j) );
        }
}

int C(int n, int k)
{
    if (k < 0 || k > n) return 0;
    int ans = 1;
    for (int i = n - k + 1; i <= n; i++)
        ans = mul(ans, i);
    for (int i = 1; i <= k; i++)
        ans = mul(ans, rev[i] );
    return ans;
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    init();

    int n, k;
    scanf("%d%d", &n, &k);

    int ans = 0;
    for (int i = 1; i <= k && i <= n; i++)
    {
        int cur = dp[k][i];
        cur = mul(cur, fact[i] );
        cur = mul(cur, C(n, i) );
        sadd(ans, mul(cur, fpow(2, n - i) ) );
    }
    printf("%d\n", ans);



	return 0;
}