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

const int MAXN = (int)2e5 + 5;
const lint INF = (lint)1e18 + 5;

lint ar[MAXN];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
        scanf("%lld", &ar[i]);
    while (n > 1 && ar[n - 1] == 0)
        --n;
    if (n == 1)
    {
        if (ar[0] == 0)
            printf("Yes\n");
        else
            printf("No\n");
        return;
    }
    if (ar[n - 1] > 0 || ar[0] <= 0)
    {
        printf("No\n");
        return;
    }
    --ar[0];
    ++ar[n - 1];
    for (int i = 0; i + 1 < n; ++i)
    {
        if (ar[i] < 0)
        {
            printf("No\n");
            return;
        }
        ar[i + 1] += ar[i];
    }
    if (ar[n - 1] == 0)
        printf("Yes\n");
    else
        printf("No\n");
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