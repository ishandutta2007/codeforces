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

char s[50][51];
const int OFFSET[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int bp[32768][26];

int gett(int x, int y)
{
    if (0 <= x && x < 50 && 0 <= y && y < 50)
        return s[x][y] ? s[x][y] - '0' : s[x][y];
    return 0;
}

int mov(int state)
{
    int dir = state & 3;
    int dir2 = (state >> 2) & 1;
    int x = (state >> 3) & 63;
    int y = (state >> 9);
    int cur = gett(x, y);
    if (!cur)
        return state;
    while (true)
    {
        int x2 = x + OFFSET[dir][0];
        int y2 = y + OFFSET[dir][1];
        if (gett(x2, y2) != cur)
            break;
        x = x2;
        y = y2;
    }
    int dir3 = (dir + dir2 * 2 + 3) % 4;
    while (true)
    {
        int x2 = x + OFFSET[dir3][0];
        int y2 = y + OFFSET[dir3][1];
        if (gett(x2, y2) != cur)
            break;
        x = x2;
        y = y2;
    }
    int x2 = x + OFFSET[dir][0];
    int y2 = y + OFFSET[dir][1];
    int nxt = gett(x2, y2);
    int res;
    if (nxt)
        res = dir | (dir2 << 2) | (x2 << 3) | (y2 << 9);
    else if (dir2)
        res = ((dir + 1) % 4) | ((dir2 - 1) << 2) | (x << 3) | (y << 9);
    else
        res = dir | ((dir2 + 1) << 2) | (x << 3) | (y << 9);
    if (res < 0 || res >= 32768)
        throw;
}

void solve()
{
    int n, k;
    scanf("%d %d", &n, &k);
    For(i, n)
        scanf("%s", s[i]);
    For(i, 32768)
        bp[i][0] = mov(i);
    For(j, 25) For(i, 32768)
        bp[i][j + 1] = bp[bp[i][j]][j];
#ifdef LOCAL
    int pos = 0;
    For(i, k)
    {
        pos = mov(pos);
    }
#endif
    int cur = 0;
    for (int j = 25; j >= 0; --j)
        if (k & (1 << j))
        {
            k -= 1 << j;
            cur = bp[cur][j];
        }
    printf("%d\n", gett((cur >> 3) & 63, cur >> 9));
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