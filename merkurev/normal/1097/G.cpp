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

const int MOD = (int) 1e9 + 7;
const unsigned long long MOD28 = MOD * 8ULL * MOD;

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
int mul(long long a, long long b)
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
    return mul(a, rev(b));
}



const int N = (int) 1e5 + 100;
vector <int> g[N];
const int K = 256;

int k;
int dp[N][K]; // / j!

unsigned long long A[K], B[K], C[K];
void pmul()
{
    memset(C, 0, sizeof C);
   int it = 0;
    for (int i = 0; i <= k; i++)
    {
        it++;
        if (it % 8 == 0)
        {
            for (int j = 0; j <= k; j++)
                if (C[j] >= MOD28)
                    C[j] -= MOD28;
        }
        unsigned long long x = A[i];
        if (x == 0) continue;
        for (int j = 0; j <= k - i; j++)
        {
            C[i + j] += B[j] * x;
        }
    }
    for (int j = 0; j <= k; j++)
        C[j] %= MOD;
}

void dpmul(int a, int b, int c)
{
    for (int i = 0; i <= k; i++)
    {
        A[i] = dp[a][i];
        B[i] = dp[b][i];
    }
    
    pmul();

    for (int i = 0; i <= k; i++)
        dp[c][i] = C[i];
}

int fact[K], rfact[K], ri[K];

int answer = 0;
void dfs(int v, int par)
{
    dp[v][0] = 1;
    int sumCh = 0;
    
    for (int to : g[v])
    {
        if (to == par) continue;
        dfs(to, v);
        dpmul(v, to, N - 1);
        sadd(sumCh, dp[to][k]);

        for (int i = 0; i <= k; i++)
            sadd(dp[v][i], dp[N - 1][i]); 
    }

    sadd(answer, dp[v][k]);
    sadd(answer, dp[v][k]);
    ssub(answer, sumCh);
//    eprintf("answer = %d\n", answer);
/*
    for (int i = 0; i <= k; i++)
        if (dp[v][i] != 0)
            eprintf("dp(%d, %d) = %d\n", v, i, dp[v][i]);
    
    eprintf("-------\n");
*/
    memset(dp[N - 2], 0, sizeof dp[N - 2]);
    for (int i = 0; i <= k; i++)
        dp[N - 2][i] = rfact[i];
    dpmul(v, N - 2, v);

    for (int i = 0; i <= k; i++)
    {
        ssub(dp[v][i], rfact[i]);
        sadd(dp[v][i], dp[v][i]);
        sadd(dp[v][i], rfact[i]);
    }
/*
    for (int i = 0; i <= k; i++)
        if (dp[v][i] != 0)
            eprintf("dp(%d, %d) = %d\n", v, i, dp[v][i]);
    eprintf("=====================\n");
 */   
}


void init()
{
    fact[0] = 1;
    rfact[0] = 1;
    ri[1] = 1;
    for (int i = 1; i < K; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        if (i > 1)
            ri[i] = sub(0, mul(MOD / i, ri[MOD % i]));
        rfact[i] = mul(rfact[i - 1], ri[i]);
    }

}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    init();

    int n;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);

    answer = mul(answer, fact[k]);
    printf("%d\n", answer);

	return 0;
}