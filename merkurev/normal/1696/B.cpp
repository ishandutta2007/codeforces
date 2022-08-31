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



void solve()
{
    int n;
    scanf("%d", &n);
    bool f1 = false;
    bool f10 = false;
    bool f101 = false;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 0 && f1)
            f10 = true;
        if (x != 0)
            f1 = true;
        if (x != 0 && f10)
            f101 = true;
    }
    if (f101)
        printf("2\n");
    else if (f1)
        printf("1\n");
    else
        printf("0\n");
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}