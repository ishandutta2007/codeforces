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


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    long long ans = 0;
    map <long long, int> cnt;
    long long suff = 0;
    long long pref = sum;
    for (int i = n - 1; i >= 1; i--)
    {
        pref -= a[i];
        
        long long rem = sum - pref;
        eprintf("rem = %lld / %lld\n", rem, sum);
        
        if (3 * pref == sum && rem % 2 == 0)
        {
            ans += cnt[rem / 2];
        }

        suff += a[i];
        eprintf("suff = %lld\n", suff);
        cnt[suff]++;
    }

    printf("%lld\n", ans);

	return 0;
}