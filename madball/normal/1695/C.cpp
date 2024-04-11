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
#include <bitset>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = (int)1e5 + 5;
const int INF = (int)1e9 + 7;

int mn[1001][1001];
int mx[1001][1001];
int ar[1001][1001];

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    For(i, n) For(j, m)
    {
        mn[i][j] = INF;
        mx[i][j] = -INF;
        scanf("%d", &ar[i][j]);
    }
    if ((n + m) % 2 == 0)
    {
        printf("NO\n");
        return;
    }
    mn[0][0] = mx[0][0] = ar[0][0];
    For(i, n) For(j, m)
    {
        if (i)
        {
            mn[i][j] = min(mn[i][j], mn[i - 1][j]);
            mx[i][j] = max(mx[i][j], mx[i - 1][j]);
        }
        if (j)
        {
            mn[i][j] = min(mn[i][j], mn[i][j - 1]);
            mx[i][j] = max(mx[i][j], mx[i][j - 1]);
        }
        if (i + j)
        {
            mn[i][j] += ar[i][j];
            mx[i][j] += ar[i][j];
        }
    }
    if (mn[n - 1][m - 1] <= 0 && mx[n - 1][m - 1] >= 0)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    For(i, t)
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}