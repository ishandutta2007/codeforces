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

const int MOD = 998244353;

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

const int M = 55;
int m;


long long bit(long long x, int id)
{
    return (x >> id) & 1LL;
}

long long g[M];
int col[M];
int id[M];

bool addRow(int row)
{
    for (int i = 0; i < row; i++)
    {
        if (bit(g[row], col[i]))
            g[row] ^= g[i];
    }
    for (int i = 0; i < m; i++)
        if (bit(g[row], i))
        {
            col[row] = i;

            for (int j = 0; j < row; j++)
                if (bit(g[j], i))
                    g[j] ^= g[row];

            return true;
        }
    return false;
}

const int BOUND = 24;//28;
const int RM = 14;

int ans[M];
int dp[M][M][1 << RM];

int sz;

void gen(int pos, long long val)
{
    if (pos == sz)
    {
        ans[__builtin_popcountll(val)]++;
        return;
    }
    gen(pos + 1, val);
    gen(pos + 1, val ^ g[pos]);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &g[sz]);
        if (addRow(sz))
            sz++;
    }

    long long k = 1;
    for (int i = sz; i < n; i++)
        k = mul(k, 2);

    if (sz <= BOUND)
    {
        gen(0, 0LL);
    }
    else
    {
        for (int i = 0; i < sz; i++)
            id[col[i]] = -1;
        int cid = 0;
        for (int i = 0; i < m; i++)
            if (id[i] != -1)
                id[i] = cid++;
        
        //eprintf("sz = %d, cid = %d\n", sz, cid);
        //for (int i = 0; i < sz; i++)
        //    eprintf("%lld (%d)\n", g[i], col[i]);

        for (int i = 0; i < sz; i++)
        {
            long long cur = 0;
            for (int j = 0; j < m; j++)
                if (id[j] != -1)
                    cur ^= (bit(g[i], j) << id[j]);
            g[i] = cur;
        }

        //for (int i = 0; i < sz; i++)
        //    eprintf("%lld\n", g[i]);
        dp[0][0][0] = 1;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j <= i; j++)
                for (int mask = 0; mask < (1 << cid); mask++)
                {
                    int cur = dp[i][j][mask];
                    if (cur == 0)
                        continue;
                    sadd(dp[i + 1][j][mask], cur);
                    sadd(dp[i + 1][j + 1][mask ^ g[i]], cur);
                }
        for (int i = 0; i <= sz; i++)
            for (int mask = 0; mask < (1 << cid); mask++)
                sadd(ans[i + __builtin_popcount(mask)], dp[sz][i][mask]);

    }

    for (int i = 0; i <= m; i++)
        ans[i] = mul(ans[i], k);

    for (int i = 0; i <= m; i++)
        printf("%d ", ans[i]);
    printf("\n");


	return 0;
}