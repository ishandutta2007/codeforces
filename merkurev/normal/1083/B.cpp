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


const int N = (int) 5e5 + 100;
char s[N], t[N];

int main(int,  char **)
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);

    scanf("%s%s", s, t);

    long long cnt = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 1)
        {
            if (s[i] != t[i])
                cnt = 2;
        }
        else
        {
            long long ncnt = 2;
            if (s[i] == 'a')
                ncnt += 1;
            if (t[i] == 'b')
                ncnt += 1;
            ncnt += (cnt - 2) * 2;
            cnt = ncnt;
        }
        cnt = min(cnt, (long long)k);
        ans += cnt;
    }
    printf("%lld\n", ans);

	return 0;
}