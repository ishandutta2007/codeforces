#include <bits/stdc++.h>
using namespace std;

const int way_x[] = {0, 0, -1, 1}, way_y[] = {-1, 1, 0, 0};
int board[100010];
int n, m;

bool check(int a, int b)
{
    int x1 = a / m;
    int y1 = a % m;
    int x2 = b / m;
    int y2 = b % m;
    for (int i = 0; i < 4; i++)
        if (x1 + way_x[i] == x2 && y1 + way_y[i] == y2)
            return 1;
    return 0;
}

bool dfs(int pos)
{
    if (pos == n * m)
        return 1;
    int x = pos / m;
    int y = pos % m;
    for (int i = pos; i < n * m; i++)
    {
        swap(board[pos], board[i]);
        if ((x && check(board[pos], board[(x - 1) * m + y])) || (y && check(board[pos], board[x * m + y - 1])))
            continue;
        if (dfs(pos + 1))
            return 1;
        swap(board[pos], board[i]);
    }
    return 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n * m; i++)
        board[i] = i;
    if (dfs(0))
    {
        puts("YES");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", board[i * m + j] + 1);
            puts("");
        }
    }
    else
        puts("NO");
    return 0;
}