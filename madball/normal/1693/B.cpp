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
const int INF = (int)1e9 + 7;
int par[MAXN];
int inp[MAXN][2];
int mx[MAXN];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n - 1)
    {
        scanf("%d", &par[i + 1]);
        --par[i + 1];
    }
    For(i, n)
        scanf("%d %d", &inp[i][0], &inp[i][1]);
    fill(mx, mx + n, 0);
    int res = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (mx[i] < inp[i][0])
        {
            ++res;
            mx[i] = inp[i][1];
        }
        if (mx[i] > inp[i][1])
            mx[i] = inp[i][1];
        mx[par[i]] += mx[i];
        if (mx[par[i]] > INF)
            mx[par[i]] = INF;
    }
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