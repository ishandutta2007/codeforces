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

const long long INF = (long long) 2e18;

const int N = 1005;

char s[N];
int lcp[N][N];

vector <pair <int, int>> segs;

bool cmp(pair <int, int> a, pair <int, int> b)
{
    int alen = a.second - a.first;
    int blen = b.second - b.first;
    int clen = min(alen, blen);
    int com = lcp[a.first][b.first];
    
    if (com < clen)
        return s[a.first + com] < s[b.first + com];

    return alen < blen;
}
    
int n, m;
int mn[N];

long long dp[N][N];

void sadd(long long &a, long long b)
{
    a += b;
    if (a >= INF)
        a = INF;
}

long long getCntGEQ(int id)
{
    for (int i = 0; i < n; i++)
        mn[i] = n + 1;
    for (int i = id; i < (int) segs.size(); i++)
        mn[segs[i].first] = min(mn[segs[i].first], segs[i].second);
/*
    for (int i = 0; i < n; i++)
        eprintf("%d ", mn[i]);
    eprintf("\n");
*/
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
        {
            long long cur = dp[i][j];
            if (i != 0)
                sadd(dp[i + 1][j], cur);
            sadd(dp[mn[i]][j + 1], cur);
        }

    //eprintf("ans = %lld\n", dp[n][m]);
    //throw;
    return dp[n][m];
}

void printStr(pair <int, int> p)
{
    int l = p.first, r = p.second;
    for (int i = l; i < r; i++)
        printf("%c", s[i]);
    printf("\n");
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    long long k;
    scanf("%d%d%lld", &n, &m, &k);
    scanf("%s", s);
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (s[i] == s[j])
                lcp[i][j] = 1 + lcp[i + 1][j + 1];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            segs.emplace_back(i, j);

    sort(segs.begin(), segs.end(), cmp);

  //  getCntGEQ(0);

    int lb = -1, rb = (int) segs.size();

    while (rb - lb > 1)
    {
        int mb = (lb + rb) / 2;
        long long cur = getCntGEQ(mb);
#ifdef LOCAL
        //printStr(segs[mb]);
        //printf("%lld\n", cur);
#endif
        if (cur >= k)
            lb = mb;
        else
            rb = mb;
    }
    //eprintf("lb = %d, rb = %d\n", lb, rb);
    printStr(segs[lb]);
	return 0;
}