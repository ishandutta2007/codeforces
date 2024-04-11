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

const int MOD = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int ans[1000001];

void solve()
{
    ans[0] = 1;
    int s = 0;
    for (int i = 1; i <= 1000000; ++i)
    {
        int wut = 1;
        int j = i;
        for (int k = 2; k * k <= j; ++k)
            if (j % k == 0)
            {
                j /= k;
                int cnt = 1;
                while (j % k == 0)
                {
                    j /= k;
                    ++cnt;
                }
                wut *= cnt + 1;
            }
        if (j > 1)
            wut *= 2;
        ans[i] = add(s, wut);
        s = add(s, ans[i]);
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", ans[n]);
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
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}