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

const int N = (int) 1e5;
long long a[N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    int ans = 0;
    long long mx = a[0];
    for (int i = 0; i < n; i++)
    {
        long long cd = max(0LL, mx - a[i]);
        mx = max(mx, a[i]);

        int cur = 0;
        while (cd > 0)
        {
            cd -= (1LL << cur);
            cur++;
        }
        ans = max(ans, cur);
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