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

void solve()
{
    int n;
    scanf("%d", &n);
    static int ar[100000];
    static int br[100000];
    int a = 0, b = 0;
    For(i, n * 2)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x = abs(x);
        y = abs(y);
        if (x == 0)
            ar[a++] = y;
        else
            br[b++] = x;
    }
    sort(ar, ar + n);
    sort(br, br + n);
    double res1 = 0, res2 = 0;
    For(i, n)
        res1 += sqrt((double)ar[i] * ar[i] + (double)br[i] * br[i]);
    reverse(ar, ar + n);
    For(i, n)
        res2 += sqrt((double)ar[i] * ar[i] + (double)br[i] * br[i]);
    printf("%.15lf\n", min(res1, res2));
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