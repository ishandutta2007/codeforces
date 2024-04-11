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

const int INF = (int) 1e9 + 100;
const int N = (int) 1e5 + 100;
int p[N], s[N], mn[N];
vector <int> ch[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &p[i]);
        p[i]--;
        ch[p[i]].push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        mn[i] = INF;
        scanf("%d", &s[i]);
    }

    long long ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mn[i] == INF && s[i] == -1)
        {
            s[i] = s[p[i]];
        }
        if (s[i] > mn[i])
        {
            printf("-1\n");
            return 0;
        }
        if (s[i] == -1)
            s[i] = mn[i];

        if (i != 0)
            mn[p[i] ] = min(mn[p[i]], s[i]);
    }
    for (int i = 1; i < n; i++)
        ans += s[i] - s[p[i]];
    ans += s[0];

    printf("%lld\n", ans);


	return 0;
}