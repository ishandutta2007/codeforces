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

const int MAXN = (int)3e5 + 10;
int height[MAXN];
int value[MAXN];
int lef[MAXN];
int righ[MAXN];
int par[MAXN];

lint doit(int v, bool is_left = false, bool is_right = false)
{
    lint left_ans = lef[v] == -1 ? 0 : doit(lef[v], true, is_right);
    lint right_ans = righ[v] == -1 ? 0 : doit(righ[v], is_left, true);
    lint ans = (lint)value[v] + left_ans + right_ans;
    if (is_left)
        ans = max(ans, left_ans);
    if (is_right)
        ans = max(ans, right_ans);
    return ans;
}

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
        lef[i] = righ[i] = -1;
    For(i, n)
    {
        scanf("%d", &height[i]);
        if (i == 0)
        {
            par[i] = -1;
            continue;
        }
        if (height[i - 1] < height[i])
        {
            righ[i - 1] = i;
            par[i] = i - 1;
            continue;
        }
        int j = i - 1;
        while (par[j] >= 0 && height[par[j]] > height[i])
            j = par[j];
        par[i] = par[j];
        if (par[i] != -1)
            righ[par[i]] = i;
        par[j] = i;
        lef[i] = j;
    }
    For(i, n)
        scanf("%d", &value[i]);
    int root = 0;
    For(i, n)
    {
        if (par[i] == -1)
            root = i;
    }
    printf("%lld\n", doit(root));
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