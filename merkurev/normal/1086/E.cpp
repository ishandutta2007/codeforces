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

const int N = 2005;
int dp[N][N];
int deg[N];
int fact[N];
int a[N][N];
bool used[N], usedp[N];


struct Fn
{
    int fn[N];

    Fn() : fn() 
    {
        memset(fn, 0, sizeof fn);
    }

    void clear()
    {
        memset(fn, 0, sizeof fn);
    }

    void add(int pos, int x)
    {
        pos++;
        for (; pos < N; pos = (pos | (pos - 1)) + 1)
            fn[pos] += x;
    }


    int sum(int pos)
    {
        pos++;
        int ans = 0;
        for (; pos > 0; pos = (pos & (pos - 1)))
            ans += fn[pos];
        return ans;
    }
};

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }

    fact[0] = 1;
    for (int i = 1; i < n; i++)
        fact[i] = mul(fact[i - 1], i);

    dp[0][0] = 1;
    for (int rem = 1; rem < N; rem++)
        for (int nw = 0; nw <= rem; nw++)
        {
            int old = rem - nw;
            if (old > 0)
            {
                sadd(dp[rem][nw], mul(dp[rem - 1][nw + 1], old - 1));
                if (nw > 0)
                    sadd(dp[rem][nw], mul(dp[rem - 1][nw], nw));
            }
            else
            {
                sadd(dp[rem][nw], mul(dp[rem - 1][nw - 1], nw));
            }
        }
    deg[0] = 1;
    for (int i = 1; i < N; i++)
        deg[i] = mul(deg[i - 1], dp[n][0]);


    Fn unused = Fn(), usedPrev = Fn();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        //eprintf("-----\n");
        unused.clear();
        usedPrev.clear();
        memset(used, false, sizeof used);
        memset(usedp, false, sizeof usedp);
        for (int j = 0; j < n; j++)
            unused.add(j, 1);

        int ndeg = deg[n - i - 1];
        for (int j = 0; j < n; j++)
        {
            int x = -1;
            if (i != 0)
            {
                x = a[i - 1][j];
                if (!used[x])
                {
                    usedp[x] = true;
                    unused.add(x, -1);
                }
            }

            int y = a[i][j];
            int lessUnused = unused.sum(y - 1);
            int lessUsedPrev = usedPrev.sum(y - 1);

            int usedPrevX = usedPrev.sum(n);
            if (x != -1 && !used[x])
                usedPrevX++;

            //eprintf("x = %d, y = %d, lessUnused = %d, lessUsedPrev = %d, usedPrevX = %d\n", x, y, lessUnused, lessUsedPrev, usedPrevX);
            int contUnused = fact[n - j - 1];
            if (i != 0)
                contUnused = dp[n - j - 1][usedPrevX];

            int contUsedPrev = fact[n - j - 1];
            if (i != 0 && usedPrevX > 0)
                contUsedPrev = dp[n - j - 1][usedPrevX - 1];
            
            contUnused = mul(contUnused, ndeg);
            contUsedPrev = mul(contUsedPrev, ndeg);

            sadd(ans, mul(lessUnused, contUnused));
            sadd(ans, mul(lessUsedPrev, contUsedPrev));

            used[y] = true;
            if (usedp[y])
                usedPrev.add(y, -1);
            else
                unused.add(y, -1);

            if (i != 0)
            {
                if (!used[x])
                    usedPrev.add(x, 1);
            }

            //if (ans > 0)
            //    eprintf("i = %d, j = %d : %d\n", i, j, ans);
        }
    }

    printf("%d\n", ans);


	return 0;
}