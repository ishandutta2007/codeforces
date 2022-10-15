#include <bits/stdc++.h>
using namespace std;

const int way_x[4] = {-1, 1, 0, 0}, way_y[4] = {0, 0, -1, 1};

struct node
{
    int x, y, tl, tr;
    inline bool operator>(const node &b) const
    {
        return this->tl + this->tr > b.tl + b.tr;
    }
};

char board[2005][2005];
bool visit[2005][2005];
priority_queue<node, vector<node>, greater<node> > que;

int main()
{
    int n, m, r, c, x, y;
    scanf("%d%d%d%d%d%d", &n, &m, &r, &c, &x, &y);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c = getchar();
            while (c != '.' && c != '*')
                c = getchar();
            board[i][j] = c;
        }
    que.push((node){r, c, 0, 0});
    int answer = 0;
    while (!que.empty())
    {
        node cac = que.top();
        que.pop();
        if (cac.tl > x || cac.tr > y)
            continue;
        if (visit[cac.x][cac.y])
            continue;
        visit[cac.x][cac.y] = true;
        answer++;
        for (int i = 0; i < 4; i++)
        {
            int tx = cac.x + way_x[i], ty = cac.y + way_y[i];
            if (tx && tx <= n && ty && ty <= m && board[tx][ty] == '.')
                que.push((node){tx, ty, cac.tl + (i == 2), cac.tr + (i == 3)});
        }
    }
    printf("%d\n", answer);
    return 0;
}