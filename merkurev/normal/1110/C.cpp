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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int fast(int n)
{
    int t = 1;
    while (t <= n)
        t *= 2;
    int x = (t - 1) ^ n;
    int ans = gcd(n ^ x, n & x);
    if (x == 0 || x == n)
        ans = 1;

    if (ans == 1)
    {
        for (int tt = 2; tt * tt <= n; tt++)
        {
            if (n % tt == 0)
            {
                x = n / tt;
                ans = gcd(n ^ x, n & x);
                break;
            }
        }
    }

    return ans;
}

int slow(int n)
{
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, gcd(n & i, n ^ i));
    return ans;
}


void stress()
{
    for (int i = 2; i <= 1000; i++)
    {
        eprintf("%d) %d %d\n", i, slow(i), fast(i));
        if(slow(i) != fast(i)) throw;
    }
}

void solve()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", fast(n));
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

#ifdef LOCAL
    //stress();
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();
	return 0;
}