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

int ar[100500];
int br[100500];

int read()
{
    char c;
    while (true)
    {
        c = getchar();
        if ('0' <= c && c <= '9')
            break;
    }
    int res = c - '0';
    while (true)
    {
        c = getchar();
        if (!('0' <= c && c <= '9'))
            return res;
        res = res * 10 + c - '0';
    }
}

void solve()
{
    int n = read();
    int mn = (int)1e9, mx = 0;
    For(i, n)
    {
        ar[i] = read();
        mn = min(mn, ar[i]);
        mx = max(mx, ar[i]);
    }
    if (mx - mn > 100100)
    {
        printf("NO\n");
        return;
    }
    bool res = true;
    For(i, n)
        ++br[ar[i] - mn];
    --br[0];
    --br[mx - mn];
    for (int i = mn + 1; i < mx; ++i)
    {
        br[i - mn] -= 2;
        if (br[i - mn] < 0)
            res = false;
    }
    for (int i = mn; i <= mx; ++i)
    {
        if (br[i - mn] > 0)
        {
            if (br[i - mn + 1] < br[i - mn])
                res = false;
            else
            {
                br[i - mn + 1] -= br[i - mn];
                br[i - mn] = 0;
            }
        }
    }
    if (res)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef STRESS_GEN
    For(_, 1000)
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}