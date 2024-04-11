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

const long long INF = (long long) 4e18;
const int N = (int) 1e5 + 100;

long long sqr(long long x)
{
    return x * x;
}

long long getVal(long long a, long long b, long long c)
{
    return sqr(a - b) + sqr(a - c) + sqr(b - c);
}

int n[3];
int a[3][N];

void solve()
{
    for (int i = 0; i < 3; i++)
        scanf("%d", &n[i]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n[i]; j++)
            scanf("%d", &a[i][j]);
        sort(a[i], a[i] + n[i]);
    }

    long long ans = INF;
    for (int mid = 0; mid < 3; mid++)
    {
        for (int t = 1; t <= 2; t++)
        {
            int s = (mid + t) % 3;
            int b = (mid + (t ^ 3)) % 3;
            int j = 0, h = 0;
            for (int i = 0; i < n[mid]; i++)
            {
                while (j + 1 < n[s] && a[s][j + 1] <= a[mid][i])
                    j++;
                while (h + 1 < n[b] && a[b][h] < a[mid][i])
                    h++;

                long long cur = getVal(a[mid][i], a[s][j], a[b][h]);
                ans = min(cur, ans);
            }
        }
    }
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