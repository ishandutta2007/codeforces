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

const int INF = (int) 2e9;

void solve()
{
    int n;
    scanf("%d", &n);

    int mn = -1, mx = -1;
    int bstl = INF, bstr = INF, bstfull = INF;

    for (int i = 0; i < n; i++)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
    
        if (mn == -1 || l < mn)
        {
            mn = l;
            bstl = INF;
            bstfull = INF;
        }
        if (mx == -1 || r > mx)
        {
            mx = r;
            bstr = INF;
            bstfull = INF;
        }
        if (l == mn)
            bstl = min(bstl, c);
        if (r == mx)
            bstr = min(bstr, c);
        if (l == mn && r == mx)
            bstfull = min(bstfull, c);
    
        int ans = min(bstl + bstr, bstfull);
        printf("%d\n", ans);
    }

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