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

const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = (int) 1e6 + 100;
char s[N];
int clen[N];
int slen[N];
int dp[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    
    scanf("%s", s);
    int n = strlen(s);

    
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            len = 0;
        }
        else
        {
            clen[i] = len++;
        }
    }

    int ans = 0;

    int suf0 = 0;
    while (suf0 < n && s[n - 1 - suf0] == '0')
        suf0++;

    if (suf0 == n)
    {
        printf("%d\n", n);
        return 0;
    }

    int pref0 = 0;
    while (s[pref0] == '0')
        pref0++;

    int cur = pref0 + 1;
    int cur0 = 0;

    for (int i = pref0; i < n; i++)
    {
        if (s[i] == '1')
        {
            sadd(ans, cur);
            sadd(cur0, cur);
        }
        else
        {
            int cc = clen[i];
            int cx = sub(cur0, slen[cc]);
            //eprintf("i = %d, cc = %d, cx = %d\n", i, cc, cx);
            if (cc < suf0)
                sadd(ans, cx);
            slen[cc] = cur0;
            sadd(cur, cx);
        }
    }


    printf("%d\n", ans);

	return 0;
}