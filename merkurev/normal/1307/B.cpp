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



void solve()
{
    int n, x;
    scanf("%d%d", &n, &x);

    vector <int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (find(a.begin(), a.end(), x) != a.end())
    {
        printf("1\n");
        return;
    }
    int mx = *max_element(a.begin(), a.end());
    int cnt = max(2, (x + mx - 1) / mx);

    printf("%d\n", cnt);
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