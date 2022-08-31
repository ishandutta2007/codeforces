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
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0) a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
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
int rev(int x)
{
    return fpow(x, MOD - 2);
}
int divi(int a, int b)
{
    return mul(a, rev(b) );
}


const int N = 1005;
int dp[N][N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int k, pa, pb;
    scanf("%d%d%d", &k, &pa, &pb);
    int sum = (pa + pb);
    pa = divi(pa, sum);
    pb = divi(pb, sum);
    int rpb = rev(pb);

    int ans = 0;
    dp[1][0] = 1;
    for (int ca = 1; ca <= k; ca++)
        for (int cab = 0; cab < k; cab++)
        {
            int curP = dp[ca][cab];
//            eprintf("ca = %d, cab = %d : curP = %d\n", ca, cab, curP);

            if (ca < k)
            {
                sadd(dp[ca + 1][cab], mul(pa, curP) );
                
                if (ca + cab < k)
                {
                    sadd(dp[ca][ca + cab], mul(pb, curP) );
                }
                else
                {
                    int x = add(cab, ca);
                    sadd(ans, mul(pb, mul(curP, x) ) );
                }
            }
            else
            {
//                eprintf("rpb = %d, ca = %d, cab = %d\n", rpb, ca, cab);
                int x = add(add(cab, ca), sub(rpb, 1) );
                sadd(ans, mul(x, curP) );
            }
        }
    printf("%d\n", ans);


	return 0;
}