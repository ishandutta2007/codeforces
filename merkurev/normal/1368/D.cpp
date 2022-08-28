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


const int K = 21;
int cnt[K];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < K; j++)
            cnt[j] += (x >> j) & 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long x = 0;
        for (int j = 0; j < K; j++)
            if (cnt[j])
            {
                cnt[j]--;
                x += (1LL << j);
            }
        ans += x * x;
    }
    printf("%lld\n", ans);



	return 0;
}