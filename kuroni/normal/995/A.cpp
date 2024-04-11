#include <iostream>
#include <cstdio>
#include <vector>
#define fi first
#define se second
#define st(u) u.fi][u.se
using namespace std;

const int N = 55;

int n, m, a[5][N];
pair<int, int> nxt[4][N], pre[4][N];
vector<pair<int, pair<int, int>>> ans;

void init()
{
    for (int i = 2; i <= n; i++)
    {
        nxt[2][i] = make_pair(2, i - 1);
        pre[2][i - 1] = make_pair(2, i);
    }
    for (int i = 1; i < n; i++)
    {
        nxt[3][i] = make_pair(3, i + 1);
        pre[3][i + 1] = make_pair(3, i);
    }

    nxt[2][1] = make_pair(3, 1);
    pre[3][1] = make_pair(2, 1);

    nxt[3][n] = make_pair(2, n);
    pre[2][n] = make_pair(3, n);
}

void move(pair<int, int> u)
{
    for (pair<int, int> cur = u; cur != nxt[st(u)]; cur = pre[st(cur)])
        if (a[st(cur)] != 0)
        {
            ans.push_back(make_pair(a[st(cur)], make_pair(nxt[st(cur)].fi, nxt[st(cur)].se)));
            swap(a[st(nxt[st(cur)])], a[st(cur)]);
        }
}

bool cycle()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[2][i] != 0 && a[st(nxt[2][i])] == 0)
        {
            move(make_pair(2, i));
            return true;
        }
        if (a[3][i] != 0 && a[st(nxt[3][i])] == 0)
        {
            move(make_pair(3, i));
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    do
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[2][i] != 0 && a[2][i] == a[1][i])
            {
                ans.push_back(make_pair(a[2][i], make_pair(1, i)));
                a[2][i] = 0;
            }
            if (a[3][i] != 0 && a[3][i] == a[4][i])
            {
                ans.push_back(make_pair(a[3][i], make_pair(4, i)));
                a[3][i] = 0;
            }
        }
    }   while (cycle());
    if (ans.empty())
        printf("-1\n");
    else
    {
        printf("%u\n", ans.size());
        for (pair<int, pair<int, int>> &v : ans)
            printf("%d %d %d\n", v.fi, v.se.fi, v.se.se);
    }
}