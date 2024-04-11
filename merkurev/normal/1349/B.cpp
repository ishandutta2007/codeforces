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


const int N = (int) 1e5 + 100;
int a[N];
int prefBal[N];
int suffBal[N];

int _sgn(int x)
{
    if (x > 0)
        return 1;
    return -1;
}


void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    bool good = true;
    bool hasK = false;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] != k)
            good = false;
        else
            hasK = true;
    }
    for (int i = 0; i < n; i++)
        prefBal[i + 1] = max(0, prefBal[i] + _sgn(a[i] >= k));
    suffBal[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suffBal[i] = max(0, suffBal[i + 1] + _sgn(a[i] >= k));

    for (int i = 0; i < n; i++)
    {
        if (a[i] < k)
            continue;
        if (i > 0 && a[i - 1] >= k)
            good = true;
        if (i + 1 < n && a[i + 1] >= k)
            good = true;
        if (i > 0 && prefBal[i - 1] + suffBal[i + 1] >= 1)
            good = true;
        if (i + 1 < n && prefBal[i] + suffBal[i + 2] >= 1)
            good = true;
        //eprintf("i = %d, good = %d\n", i, (int) good);
    }
    if (good && hasK)
        printf("yes\n");
    else
        printf("no\n");
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