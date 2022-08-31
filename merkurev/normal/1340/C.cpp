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
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


#ifdef LOCAL
const int M = 100;
const int C = 100;
#else
const int M = (int) 1e4 + 100;
const int C = 1005;
#endif
int a[M];

int dp[M][C];
pair <int, int> qu[M * C * 2];

int qul, qur;
void upd(int i, int j, int x, int ox)
{
    if (dp[i][j] == -1 || dp[i][j] > x)
    {
        dp[i][j] = x;
        if (x == ox)
            qu[--qul] = make_pair(i, j);
        else
            qu[qur++] = make_pair(i, j);
    }
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + m);
    int g, r;
    scanf("%d%d", &g, &r);

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    qul = M * C;
    qur = qul;
    qu[qur++] = make_pair(0, 0);

    long long ans = (long long) 1e18;
    while (qul < qur)
    {
        auto p = qu[qul++];
        int id = p.first;
        int t = p.second;
        int cc = dp[id][t];

        if (id == m - 1)
        {
            ans = min(ans, (r + g) * 1LL * cc + t);
            continue;
        }

        if (t == g)
        {
            upd(id, 0, cc + 1, cc);
        }
        if (id != 0)
        {
            int nt = t + a[id] - a[id - 1];
            if (nt <= g)
            {
                upd(id - 1, nt, cc, cc);
            }
        }
        {
            int nt = t + a[id + 1] - a[id];
            if (nt <= g)
            {
                upd(id + 1, nt, cc, cc);
            }
        }

    }
    if (ans >= (long long ) 1e16)
        ans = -1;
    printf("%lld\n", ans);


	return 0;
}