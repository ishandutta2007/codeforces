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
#include <intrin.h>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

int ar[100500];
int br[100500];
int cr[100500];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
        scanf("%d", &ar[i]);
    br[0] = ar[0];
    for (int i = 1; i < n; ++i)
        if (ar[i] > ar[i - 1])
        {
            br[i] = br[i - 1];
            cr[i] = cr[i - 1] + ar[i] - ar[i - 1];
        }
        else
        {
            br[i] = br[i - 1] + ar[i] - ar[i - 1];
            cr[i] = cr[i - 1];
        }
    For(i, n)
        if (br[i] < 0 || cr[i] < 0 || br[i] + cr[i] != ar[i])
        {
            printf("NO\n");
            return;
        }
    printf("YES\n");
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