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

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 0)
    {
        For(i, n / 2)
            printf("%d %d\n", i, (n - 1) ^ i);
#ifdef LOCAL
        printf("%d\n", 0);
#endif
        return;
    }
    if (k == 1)
    {
        For(i, n / 2)
            printf("%d %d\n", i, i == 0 ? n - 2 : i == 1 ? n - 1 : ((n - 1) ^ i));
#ifdef LOCAL
        printf("%d\n", 1);
#endif
        return;
    }
    if (k == n - 1)
    {
        if (n == 4)
        {
            printf("-1\n");
            return;
        }
        For(i, n / 2)
        {
            if (i == 0)
                printf("%d %d\n", 0, n - 4);
            else if (i == 1)
                printf("%d %d\n", 1, 2);
            else if (i == 2)
                printf("%d %d\n", 3, n - 3);
            else if (i == 3)
                printf("%d %d\n", n - 1, n - 2);
            else
                printf("%d %d\n", i, (n - 1) ^ i);
        }
#ifdef LOCAL
        printf("%d\n", n - 1);
#endif
        return;
    }
    static int pairr[1 << 16];
    fill(pairr, pairr + n, -1);
    pairr[k] = n - 1;
    pairr[n - 1] = k;
    if (pairr[n - 2] == -1)
    {
        pairr[n - 2] = 1;
        pairr[1] = n - 2;
    }
    if (pairr[(n - 1) ^ k] == -1)
    {
        pairr[(n - 1) ^ k] = 0;
        pairr[0] = (n - 1) ^ k;
    }
    For(i, n)
        if (pairr[i] == -1)
        {
            pairr[i] = (n - 1) ^ i;
            pairr[(n - 1) ^ i] = i;
        }
    int s = 0;
    For(i, n)
        if (pairr[i] > i)
        {
            printf("%d %d\n", i, pairr[i]);
#ifdef LOCAL
            s += i & pairr[i];
#endif
        }
#ifdef LOCAL
    printf("%d\n", s);
#endif
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