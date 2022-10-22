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

const lint INF = (lint)1e18 + 5;

int inp[205];
int order[205];
bool in_order[205];

char ans[205];
lint dp[205][205];

void relax(lint& a, lint b)
{
    a += b;
    if (a >= INF)
        a = INF;
}

lint doit(int n)
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    For(i, n) For(bal, i + 1)
    {
        if (ans[i] != ')')
            relax(dp[i + 1][bal + 1], dp[i][bal]);
        if (bal != 0 && ans[i] != '(')
            relax(dp[i + 1][bal - 1], dp[i][bal]);
    }
    return dp[n][0];
}

char ans2[205][205];

void solve()
{
    int n, m;
    lint k;
    scanf("%d %d %lld", &n, &m, &k);
    For(i, n) For(j, m)
    {
        int a;
        scanf("%d", &a);
        if (inp[i + j] == 0)
            inp[i + j] = a;
        else
            inp[i + j] = min(inp[i + j], a);
    }
    For(i, n + m - 1)
    {
        int cur = -1;
        For(j, n + m - 1)
            if ((cur == -1 || inp[j] < inp[cur]) && !in_order[j])
                cur = j;
        order[i] = cur;
        in_order[cur] = true;
    }
    n = n + m - 1;
    fill(ans, ans + n, '?');
    For(i, n)
    {
        ans[order[i]] = '(';
        lint cur = doit(n);
        if (cur < k)
        {
            ans[order[i]] = ')';
            k -= cur;
        }
    }
    n = n - m + 1;
    For(i, n) For(j, m)
        ans2[i][j] = ans[i + j];
    For(i, n)
        printf("%s\n", ans2[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}