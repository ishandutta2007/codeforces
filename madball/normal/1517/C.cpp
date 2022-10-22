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

int ar[500][500];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
        scanf("%d", &ar[i][i]);
    For(i, n)
    {
        int x = i, y = i;
        For(_, ar[i][i] - 1)
        {
            if (y > 0 && ar[x][y - 1] == 0)
                --y;
            else
                ++x;
            ar[x][y] = ar[i][i];
        }
    }
    For(i, n)
    {
        For(j, i + 1)
            printf("%d ", ar[i][j]);
        printf("\n");
    }
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
    //scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}