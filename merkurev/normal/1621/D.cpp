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


const int N = 505;
int a[N][N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        for (int j = 0; j < 2 * n; j++)
            scanf("%d", &a[i][j]);
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += a[n + i][n + j];

    ans += min({
            a[0][n], a[0][2 * n - 1],
            a[n - 1][n], a[n - 1][2 * n - 1],
            a[n][0], a[n][n - 1],
            a[2 * n - 1][0], a[2 * n - 1][n - 1]
            });
    printf("%lld\n", ans);


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