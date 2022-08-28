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


int MOD;

int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

void ssub(int &a, int b)
{
    a %= MOD;
    b %= MOD;
    
    a -= b;
    if (a < 0)
        a += MOD;
}

void solve()
{
    int d;
    scanf("%d%d", &d, &MOD);

    int lg = 0;
    while ((1 << (lg + 1)) <= d)
        lg++;

    //eprintf("-----\nlg = %d\n", lg);

    int ans = 1;
    for (int i = 0; i <= lg; i++)
    {
        int mn = (1 << i);
        int k = min(2 * mn - 1, d) - mn + 2;

        //eprintf("k = %d\n", k);

        ans = mul(ans, k);
    }

    ssub(ans, 1);

    printf("%d\n", ans);
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