#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = 502;
const int OFFSET[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int graph[MAXN][MAXN][4];
int dp[MAXN][MAXN][11];
 
void solve()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    For(i, n) For(j, m - 1)
    {
        int d = 0;
        scanf("%d", &d);
        graph[i][j][1] = graph[i][j + 1][3] = d;
    }
    For(i, n - 1) For(j, m)
    {
        int d = 0;
        scanf("%d", &d);
        graph[i][j][0] = graph[i + 1][j][2] = d;
    }
    if (k % 2)
    {
        For(i, n) For(j, m)
            printf("-1%c", (j + 1 == m ? '\n' : ' '));
        return;
    }
    memset(dp, 63, sizeof(dp));
    For(i, n) For(j, m)
        dp[i][j][0] = 0;
    For(s, k / 2) For(i, n) For(j, m)
    {
        For(dir, 4)
        {
            int i2 = i + OFFSET[dir][0];
            int j2 = j + OFFSET[dir][1];
            if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m)
            {
                dp[i2][j2][s + 1] = min(dp[i2][j2][s + 1], dp[i][j][s] + graph[i][j][dir]);
            }
        }
    }
    For(i, n) For(j, m)
        printf("%d%c", dp[i][j][k / 2] * 2, (j + 1 == m ? '\n' : ' '));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}