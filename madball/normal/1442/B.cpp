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

int ar[200500];
int in_ar[200500];
int br[200500];
int in_br[200500];

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    For(i, n)
    {
        scanf("%d", &ar[i]);
        --ar[i];
        in_ar[ar[i]] = i;
        in_br[i] = -1;
    }
    int res = 1;
    For(i, m)
    {
        scanf("%d", &br[i]);
        --br[i];
        in_br[br[i]] = i;
    }
    For(i, m)
    {
        int pos = in_ar[br[i]];
        bool left = pos != 0 && in_br[ar[pos - 1]] < i;
        bool right = pos + 1 != n && in_br[ar[pos + 1]] < i;
        res *= (int)left + (int)right;
        if (res >= 998244353)
            res -= 998244353;
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