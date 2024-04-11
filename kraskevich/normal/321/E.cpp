#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define PII pair<int, int>
#define F first
#define S second

const int INF = (int)1e9;
const int N = 4000 + 10;
const int K = 800 + 10;

int a[N][N];
int dp[N][K];
int s[N][N];
int f[N][N];
int ptr[K];
int n, k;

inline int go(int l, int r, int kk)
{
    return s[l + 1][r] + dp[l][kk - 1];
}

int main()
{
    /*ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = s[i][j] = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            dp[i][j] = INF;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            f[i][j] = a[i][j];
            if (j)
                f[i][j] += f[i][j - 1];
        }

    for (int l = 0; l < n; l++)
        for (int r = l; r < n; r++)
        {
            s[l][r] = f[r][r] - (l ? f[r][l - 1] : 0);
            if (r > l)
                s[l][r] += s[l][r - 1];
        }

    fill(ptr, ptr + K, 0);
    for (int i = 0; i < n; i++)
        dp[i][1] = s[0][i];
    for (int i = 1; i < n; i++)
    {
        for (int kk = 2; kk <= min(k, i + 1); kk++)
        {
            //ptr[kk] = max(ptr[kk], ptr[kk - 1]);
            int p = ptr[kk];
            while (p + 1 < i && go(p + 1, i, kk) <= go(p, i, kk))
                p++;
            int f = p;
            for (int t = p + 1; t < min(i, p + 101); t++)
                if (go(t, i, kk) <= go(f, i, kk))
                    f = t;
            p = f;
            while (p + 1 < i && go(p + 1, i, kk) <= go(p, i, kk))
                p++;
            dp[i][kk] = go(p, i, kk);
            ptr[kk] = p;
        }
    }

    printf("%d", dp[n - 1][k]);

    return 0;
}