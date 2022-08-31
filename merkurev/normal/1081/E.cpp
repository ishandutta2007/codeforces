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

const int MX = (int) 1e6;
const int N = (int) 1e5 + 100;
long long ans[N];

long long sqr(long long x)
{
    return x * x;
}

long long mySqrt(long long x)
{
    long long y = max((long long)sqrt((double)x) - 5, 0LL);
    while (sqr(y) < x)
        y++;
    return y;
}

bool bad(long long x)
{
    long long y = mySqrt(x);
    return sqr(y) != x;
}

int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    long long r = 0;
    for (int i = 1; i < n; i += 2)
    {
        long long x;
        scanf("%lld", &x);
        ans[i] = x;
        
        long long y = 0;
        while (y < MX && (y == 0 || bad(sqr(r + y) + x)))
        {
            y++;
        }
        //eprintf("bad(%lld) != true\n", sqr(r + y) + x);
        ans[i - 1] = sqr(r + y) - sqr(r);
        if (y == MX)
        {
            printf("No\n");
            return 0;
        }
        r = mySqrt(sqr(r + y) + x);
    }
    printf("Yes\n");
    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    printf("\n");

	return 0;
}