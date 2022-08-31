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

const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
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
    if (n == 0)
        return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1)
        a = mul(a, x);
    return a;
}
int rev(int x)
{
    return fpow(x, MOD - 2);
}
int divi(int a, int b)
{
    return mul(a, rev(b));
}

const int N = 14;
const int MASK = (1 << N);
int dp[MASK];
int bs[N];
int A[N];
int pedge[N][N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pedge[i][j] = divi(A[i], add(A[i], A[j]));

    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int sz = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))
                bs[sz++] = i;
        dp[mask] = 1;
        for (int smask = ((mask - 1) & mask); smask > 0; smask = ((smask - 1) & mask))
        {
            int val = dp[smask];
            for (int ai = 0; ai < sz; ai++)
            {
                int a = bs[ai];
                if ((smask & (1 << a)) == 0)
                    continue;
                for (int bi = 0; bi < sz; bi++)
                {
                    int b = bs[bi];
                    if ((smask & (1 << b)) == 0)
                    {
                        val = mul(val, pedge[a][b]);
                    }
                }
            }
            //eprintf("smask = %d, val = %d\n", smask, val);
            ssub(dp[mask], val);
        }

        int cur = dp[mask];
        for (int a = 0; a < n; a++)
        {
            if ((mask & (1 << a)) == 0)
                continue;
            for (int b = 0; b < n; b++)
                if ((mask & (1 << b)) == 0)
                {
                    cur = mul(cur, pedge[a][b]);
                }
        }
        //eprintf("mask = %d | dp = %d, cur = %d, sz = %d\n", mask, dp[mask], cur, sz);
        sadd(ans, mul(cur, sz));
    }
    printf("%d\n", ans);

	return 0;
}