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


const int N = (int) 1e6 + 100;
long long h[N];
long long delta[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &h[i]);

    for (int i = 0; i < n; i++)
        delta[i] = h[i + 1] - h[i];

   
    long long sumL = 0;
    for (int i = 1; i < n; i++)
    {
        delta[0] += delta[i];
        sumL += delta[i] * i;
        delta[i] = 0;
    }


    for (int i = 1; i < n; i++)
    {
        if (sumL > 0)
        {
            sumL -= i;
            delta[i] = 1;
            delta[0]--;
        }
    }
    /*
    for (int i = 0; i < n; i++)
        eprintf("%lld ", delta[i]);
    eprintf("\n");
    */
    long long k = max(0LL, sumL / n);
    //eprintf("sumL = %lld\n", sumL);
    //eprintf("k = %lld\n", k);
    delta[0] -= k;
    delta[n] += k;
    sumL -= k * n;

    if (sumL > 0)
        delta[n - sumL]--;
    
    
    h[0] = delta[0];
    for (int i = 1; i < n; i++)
        h[i] = h[i - 1] + delta[i];

    for (int i = 0; i < n; i++)
        printf("%lld ", h[i]);
    printf("\n");

	return 0;
}