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

const int MAXN = 2020;
char ar1[2][MAXN];
char ar2[2][MAXN];
char field[MAXN][MAXN];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n) For(j, n)
    {
        char c;
        scanf(" %c", &c);
        field[i][j] = c == '1';
    }
    int res = 0;
    For(i, n) for (int j = n - 1; j >= 0; --j) if (j > i)
    {
        if (field[i][j] ^ ar1[0][i] ^ ar1[1][j])
        {
            ar1[0][i] ^= 1;
            ar1[1][j] ^= 1;
            ++res;
        }
    }
    for (int i = n - 1; i >= 0; --i) For(j, n) if (i > j)
    {
        if (field[i][j] ^ ar2[0][i] ^ ar2[1][j])
        {
            ar2[0][i] ^= 1;
            ar2[1][j] ^= 1;
            ++res;
        }
    }
    For(i, n)
        if (field[i][i] ^ ar1[0][i] ^ ar1[1][i] ^ ar2[0][i] ^ ar2[1][i])
            ++res;
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
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}