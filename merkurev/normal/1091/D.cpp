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

const int N = (int) 1e6 + 100;
int fact[N];
int ri[N], rfact[N];

int C(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}


int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    fact[0] = 1;
    rfact[0] = 1;
    ri[1] = 1;

    for (int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
   
        if (i > 1)
            ri[i] = sub(0, mul(ri[MOD % i], MOD / i) );
        if (mul(i, ri[i]) != 1) throw;
        rfact[i] = mul(rfact[i - 1], ri[i]);
    }

    int n;
    scanf("%d", &n);

    int ans = fact[n];

    for (int i = 1; i < n; i++)
    {
        int cur = C(n, i);
        cur = mul(cur, fact[i]);
        cur = mul(cur, sub(fact[n - i], 1) );

        sadd(ans, cur);
    }


    printf("%d\n", ans);


	return 0;
}