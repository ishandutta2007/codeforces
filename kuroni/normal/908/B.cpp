#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int m, n, q, x, y, cur[4] = {0, 1, 2, 3}, ans = 0;
char s[55][55], in[105];

int chk()
{
    int cx = x, cy = y;
    for (int i = 1; i <= q; i++)
    {
        cx += dx[cur[in[i] - '0']];
        cy += dy[cur[in[i] - '0']];
        if (cx == 0 || cy == 0 || cx > m || cy > n)
            return 0;
        else if (s[cx][cy] == '#')
            return 0;
        else if (s[cx][cy] == 'E')
            return 1;
    }
    return 0;
}

int main()
{
    scanf("%d %d\n", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s\n", s[i] + 1);
        for (int j = 1; j <= n; j++)
            if (s[i][j] == 'S')
            {
                x = i;
                y = j;
            }
    }
    scanf("%s\n", in + 1);
    q = strlen(in + 1);
    do ans += chk(); while (next_permutation(cur, cur + 4));
    printf("%d", ans);
}