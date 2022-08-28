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




int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    long long n;
    scanf("%lld", &n);

    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    long long mn = n;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            mn = i;
            break;
        }
    }
    while (n % mn == 0)
        n /= mn;
    if (n == 1)
        printf("%lld\n", mn);
    else
        printf("1\n");



	return 0;
}