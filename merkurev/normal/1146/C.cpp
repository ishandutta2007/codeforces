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

int bit(int n, int i)
{
    return ((n >> i) & 1);
}

void solve()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        vector <int> v[2];
        for (int x = 0; x < n; x++)
            v[bit(x, i)].push_back(x);
        if (v[1].empty()) continue;
        printf("%d %d", (int) v[0].size(), (int) v[1].size());
        for (int x : v[0])
            printf(" %d", x + 1);
        for (int x : v[1])
            printf(" %d", x + 1);
        printf("\n");
        fflush(stdout);
        int x;
        scanf("%d", &x);
        ans = max(ans, x);
    }
    printf("-1 %d\n", ans);
    fflush(stdout);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}