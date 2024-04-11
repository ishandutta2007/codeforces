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
    int n, m;
    scanf("%d %d", &n, &m);
    static int ar[300000], br[300000];
    For(i, n)
    {
        scanf("%d", &ar[i]);
        --ar[i];
    }
    For(i, m)
        scanf("%d", &br[i]);
    sort(ar, ar + n);
    reverse(ar, ar + n);
    lint res = 0;
    For(i, n)
    {
        if (i < m)
            res += min(br[ar[i]], br[i]);
        else
            res += br[ar[i]];
    }
    printf("%lld\n", res);
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