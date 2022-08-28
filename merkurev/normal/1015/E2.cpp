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

#define left fjglkdfjgkls
#define right kjlasdkl

const int N = 1005;
char f[N][N];
char g[N][N];

int up[N][N], down[N][N], left[N][N], right[N][N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", f[i] + 1);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = '.';

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i][j] == '*')
            {
                up[i][j] = 1 + up[i - 1][j];
                left[i][j] = 1 + left[i][j - 1];
            }
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            if (f[i][j] == '*')
            {
                down[i][j] = 1 + down[i + 1][j];
                right[i][j] = 1 + right[i][j + 1];
            }

    vector <vector <int>> ans;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int cur = min({up[i][j], left[i][j], right[i][j], down[i][j]});
            //eprintf("%d %d %d %d\n", up[i][j], left[i][j], right[i][j], down[i][j]);
            if (cur == 1)
                cur = 0;
            up[i][j] = cur;
            down[i][j] = cur;
            left[i][j] = cur;
            right[i][j] = cur;
            if (cur > 0)
                ans.push_back({i, j, cur - 1});
        }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (right[i][j])
            {
                g[i][j] = '*';
                right[i][j + 1] = max(right[i][j + 1], right[i][j] - 1);
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (down[i][j])
            {
                g[i][j] = '*';
                down[i + 1][j] = max(down[i + 1][j], down[i][j] - 1);
            }
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            if (left[i][j])
            {
                g[i][j] = '*';
                left[i][j - 1] = max(left[i][j - 1], left[i][j] - 1);
            }
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            if (up[i][j])
            {
                g[i][j] = '*';
                up[i - 1][j] = max(up[i - 1][j], up[i][j] - 1);
            }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            eprintf("%c", g[i][j]);
        eprintf("\n");
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i][j] != g[i][j])
            {
                printf("-1\n");
                return 0;
            }

    printf("%d\n", (int) ans.size());
    for (auto p : ans)
        printf("%d %d %d\n", p[0], p[1], p[2]);





	return 0;
}