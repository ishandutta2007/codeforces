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


const int N = 1005;
int c[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    unsigned long long ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        long long x = 0;
        long long md = 0;

        for (int j = i + 1; j < n; j += 2)
        {
            long long li = -md;
            long long ri = c[i];

            long long lj = x - md;
            long long rj = c[j];

            long long add = max(0ll, -lj);
            li += add;
            lj += add;
            //eprintf("%lld .. %lld  | %lld .. %lld\n", li, ri, lj, rj);
            long long len = min(ri - li + 1, rj - lj + 1);
            if (i + 1 == j)
                len--;
            len = max(len, 0LL);
            ans += len;

            //eprintf("i = %d, j = %d : %lld\n", i, j, len);

            x -= c[j];
            md = min(md, x);
            x += c[j + 1];
        }
    }

    printf("%llu\n", ans);


	return 0;
}