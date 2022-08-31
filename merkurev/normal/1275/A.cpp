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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


int MOD;

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
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = (int) 3e5 + 100;
int fact[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int n;
    scanf("%d%d", &n, &MOD);
    
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = mul(fact[i], fact[n - i]);
        int x = n - i + 1;
        x = mul(x, x);
        cur = mul(cur, x);
        sadd(ans, cur);
    }

    printf("%d\n", ans);
	return 0;
}