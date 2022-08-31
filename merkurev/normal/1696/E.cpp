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

const int N = (int) 1e6 + 100;
int a[N];

int fact[N];
int ri[N], rfact[N];

void init()
{
    ri[1] = 1;
    fact[0] = 1;
    rfact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (i != 1)
            ri[i] = sub(0, mul(ri[MOD % i], MOD / i));
        if (mul(ri[i], i) != 1)
            throw;
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = mul(rfact[i - 1], ri[i]);
    }
}

int C(int n, int k)
{
    eprintf("C(%d, %d)\n", n, k);
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    init();

    int n;
    scanf("%d", &n);
    n++;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (a[i])
            sadd(ans, C(i + a[i], i + 1));
        eprintf("ans = %d\n", ans);
    }
    printf("%d\n", ans);

	return 0;
}