#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> node;

int train[3][105];
bool visit[3][105];
int n, k;
queue<node> que;

bool bfs(int tx, int ty)
{
    memset(visit, 0, sizeof(visit));
    while (!que.empty())
        que.pop();
    que.push((node){tx, ty});
    while (!que.empty())
    {
        node cac = que.front();
        que.pop();
        int &x = cac.first, &y = cac.second;
        if (visit[x][y])
            continue;
        visit[x][y] = true;
        if (y >= n - 1)
            return true;
        if (train[x][++y])
            continue;
        if (y == n - 1)
            return true;
        for (int i = -1; i < 2; i++)
        {
            int tx = x + i;
            if (tx < 0 || tx > 2)
                continue;
            if (train[tx][y] || train[tx][y + 1] || train[tx][y + 2])
                continue;
            que.push((node){tx, y + 2});
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(train, 0, sizeof(train));
        scanf("%d%d", &n, &k);
        int start_x = 1, start_y = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c = getchar();
                while (c == ' ' || c == '\n' || c == '\r')
                    c = getchar();
                train[i][j] = c != '.';
                if (c == 's')
                    start_x = i, start_y = j;
            }
        }
        if (bfs(start_x, start_y))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}