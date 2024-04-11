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



const long long INF = (long long) 1e18;
const int N = (int) 1e5 + 100;
long long l[N];
char str[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &l[i] );
    scanf("%s", str);

    long long cntd2 = 0;
    long long cntd3 = 0;
    long long cntd4 = 0;

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        eprintf("ans = %lld, cntd2 = %lld, cntd3 = %lld\n", ans, cntd2, cntd3);
        long long cur = l[i];

        if (str[i] == 'L')
        {
            long long x2 = min(cntd2, cur);
            ans += x2 * 2;
            cntd2 -= x2;
            cur -= x2;

            long long x3 = min(cntd3, cur);
            ans += x3 * 3;
            cntd3 -= x3;
            cur -= x3;
            
            long long x4 = min(cntd4, cur);
            ans += x4 * 4;
            cntd4 -= x4;
            cur -= x4;

            ans += cur * 6;
            cur = 0;
        }
        else if (str[i] == 'G')
        {
            cntd3 += cur;
            
            long long x2 = min(cntd2, cur);
            ans += x2 * 2;
            cntd2 -= x2;
            cntd3 += x2;
            cur -= x2;

            ans += cur * 3;
        }
        else if (str[i] == 'W')
        {
            cntd4 = INF;
            ans += cur * 2;
            cntd2 += cur;
        }
    }

    printf("%lld\n", ans);


	return 0;
}