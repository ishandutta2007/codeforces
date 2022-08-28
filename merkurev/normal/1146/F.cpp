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

void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = (int) 2e5 + 100;

int dp[N][3];
vector <int> ch[N];

int ndp[3];

void solve(int v)
{
    if (ch[v].empty())
    {
        dp[v][2] = 1;
        return;
    }
    dp[v][0] = 1;

    for (int to : ch[v])
    {
        solve(to);
        memset(ndp, 0, sizeof ndp);
        for (int cur = 0; cur <= 2; cur++)
        {
            sadd(ndp[cur], mul(dp[v][cur], dp[to][0]));
            sadd(ndp[cur], mul(dp[v][cur], dp[to][2]));
            int nx = min(2, cur + 1);
            sadd(ndp[nx], mul(dp[v][cur], dp[to][1]));
            sadd(ndp[nx], mul(dp[v][cur], dp[to][2]));
        }
        for (int i = 0; i < 3; i++)
            dp[v][i] = ndp[i];
    }


}


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
        int x;
        scanf("%d", &x);
        x--;
        ch[x].push_back(i);
    }
    solve(0);
    printf("%d", add(dp[0][0], dp[0][2]));



	return 0;
}