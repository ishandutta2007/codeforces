#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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
long long a[N], b[N];

set <vector <long long>> S;
vector <vector <long long>> qu;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    for (int i = 0; i < n; i++)
        scanf("%lld", &b[i]);

    if (a[0] != b[0] || a[n - 1] != b[n - 1])
    {
        printf("No\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i + 1] - a[i];
        b[i] = b[i + 1] - b[i];
    }
    n--;
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");

/*
    vector <long long> v({a, a + n});
    S.insert(v);
    qu.push_back(v);

    for (int it = 0; it < (int) qu.size(); it++)
    {
        auto cur = qu[it];
        for (int x : cur)
            eprintf("%d ", x); eprintf("\n");
        for (int i = 1; i < n - 1; i++)
        {
            cur[i] = cur[i - 1] + cur[i + 1] - cur[i];
            if (!S.count(cur))
            {
                S.insert(cur);
                qu.push_back(cur);
            }
            cur[i] = cur[i - 1] + cur[i + 1] - cur[i];
        }
    }
*/

	return 0;
}