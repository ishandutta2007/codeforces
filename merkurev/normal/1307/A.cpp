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

const int N = 105;
int a[N];


void solve()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        if (i != 0)
            k = min(a[i], d / i);
        ans += k;
        d -= k * i;
    }
    printf("%d\n", ans);
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