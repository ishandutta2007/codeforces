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


const int LOG = 17;
const int SZ = (1 << LOG);


void upd(int &a, int b)
{
    a = max(a, b);
}

int dp[LOG + 1][SZ][4];
/*
 * 0 - no
 * 1 - UP
 * 2 - DOWN
 * 3 - BOTH
 */
int cu[4] = {0, 1, 0, 1};
int cd[4] = {0, 0, 1, 1};

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < (1 << n); i++)
        dp[0][i][0] = 0;
    for (int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        dp[0][x][1] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int len = (1 << (n - i));
        //eprintf("len = %d\n", len);
        for (int a = 0; a + 1 < len; a += 2)
        {
            int b = a + 1;
            for (int ta = 0; ta < 4; ta++)
                for (int tb = 0; tb < 4; tb++)
                {
                    int cntU = cu[ta] + cu[tb];
                    int cntD = cd[tb] + cd[ta];
                    if (dp[i][a][ta] == -1 || dp[i][b][tb] == -1)
                        continue;
                    //eprintf("i = %d, a = %d, b = %d, ta = %d, tb = %d : %d %d\n", i, a, b, ta, tb, dp[i][a][ta], dp[i][b][tb]);
                    int cur = dp[i][a][ta] + dp[i][b][tb];
                    if (cntU)
                        cur++;
                    if (cntD)
                        cur++;
                    if (cntD == 2)
                        cntD--;
                    if (cntU + cntD >= 2)
                    {
                        if (i != 0)
                            cur++;
                        upd(dp[i + 1][a / 2][3], cur);
                    }
                    else if (cntU + cntD == 0)
                    {
                        upd(dp[i + 1][a / 2][0], cur);
                    }
                    else if (cntU == 1 && cntD == 0)
                    {
                        upd(dp[i + 1][a / 2][1], cur);
                        if (i != 0)
                            cur++;
                        upd(dp[i + 1][a / 2][2], cur);
                    }
                    else if (cntD == 1 && cntU == 0)
                    {
                        upd(dp[i + 1][a / 2][2], cur + 1);
                    }
                    else throw;
                }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
        upd(ans, dp[n][0][i]);
    if (k != 0)
        ans++;

    printf("%d\n", ans);


	return 0;
}