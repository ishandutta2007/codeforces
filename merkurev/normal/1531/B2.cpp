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


map <int, int> cnt;
map <int, int> cntSq;
map <pair <int, int>, int> cntP;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    long long ans = 0;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y)
            swap(x, y);

        if (x == y)
        {
            ans += cnt[x] + cntSq[x];
            cntSq[x]++;
        }
        else
        {
            ans += cnt[x] + cnt[y] + cntSq[x] + cntSq[y] - cntP[make_pair(x, y)];
            cnt[x]++;
            cnt[y]++;
            cntP[make_pair(x, y)]++;
        }
    }
    printf("%lld\n", ans);


	return 0;
}