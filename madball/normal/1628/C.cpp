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

int ar[1000][1000];

int doit(int n)
{
    int res = 0;
    For(i, n) For(j, n)
        if (((i ^ j) & 1) == 1 && (i < j ? (i % 2 == 0 && (j - i) % 4 == 1) : (j % 2 == 0 && (i - j) % 4 == 3)))
            res ^= ar[i][j];
    return res;
}

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n) For(j, n)
        scanf("%d", &ar[i][j]);
    int res = doit(n);
    For(i, n) For(j, n / 2)
        swap(ar[i][j], ar[i][n - 1 - j]);
    res ^= doit(n);
    printf("%d\n", res);
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