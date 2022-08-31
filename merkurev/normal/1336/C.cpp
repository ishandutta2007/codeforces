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

const int MOD = 998244353;
const int N = 3005;
char t[N], s[N];
int dp[N][N];

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



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s%s", s, t);
    int n = strlen(s);
    int m = strlen(t);

    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i >= m)
            sadd(ans, dp[i][0]);
        if (i == n)
            continue;
        for (int l = 0; l <= n; l++)
        {
            int cur = dp[i][l];
            if (cur == 0)
                continue;
            if (l != 0 && (t[l - 1] == 0 || t[l - 1] == s[i]))
                sadd(dp[i + 1][l - 1], cur);
            if (i + l < N && (t[i + l] == 0 || t[i + l] == s[i]))
                sadd(dp[i + 1][l], cur);
        }
    }

    printf("%d\n", ans);

	return 0;
}