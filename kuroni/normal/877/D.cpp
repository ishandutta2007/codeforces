#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#define fi first
#define se second
#define mp make_pair
#define sta(u) u.fi][u.se
using namespace std;

const int M = 1005, N = 1005;

int m, n, k, dst[M][N], hi[M][N], lo[M][N], le[M][N], ri[M][N];
char s[M][N];
queue<pair<int, int>> q;
set<int> row[M], col[N];
pair<int, int> st, en;

void init()
{
    for (int i = 0; i <= m + 1; i++)
        for (int j = 0; j <= n + 1; j++)
            hi[i][j] = lo[i][j] = le[i][j] = ri[i][j] = -1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            hi[i][j] = (s[i][j] == '#' ? -1 : min(hi[i - 1][j] + 1, k));
    for (int i = m; i >= 1; i--)
        for (int j = 1; j <= n; j++)
            lo[i][j] = (s[i][j] == '#' ? -1 : min(lo[i + 1][j] + 1, k));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            le[i][j] = (s[i][j] == '#' ? -1 : min(le[i][j - 1] + 1, k));
    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 1; j--)
            ri[i][j] = (s[i][j] == '#' ? -1 : min(ri[i][j + 1] + 1, k));
}

void push(pair<int, int> u, int val)
{
    dst[sta(u)] = val;
    row[u.fi].erase(u.se);
    col[u.se].erase(u.fi);
    q.push(u);
}

void BFS()
{
    for (push(st, 0); !q.empty(); q.pop())
    {
        pair<int, int> u = q.front();
        if (u == en)
        {
            printf("%d", dst[sta(u)]);
            return;
        }
        while (!row[u.fi].empty() && *prev(row[u.fi].end()) > u.se)
        {
            int cur = *row[u.fi].lower_bound(u.se);
            if (cur <= u.se + ri[sta(u)])
                push(mp(u.fi, cur), dst[sta(u)] + 1);
            else
                break;
        }
        while (!row[u.fi].empty() && *row[u.fi].begin() < u.se)
        {
            int cur = *prev(row[u.fi].lower_bound(u.se));
            if (cur >= u.se - le[sta(u)])
                push(mp(u.fi, cur), dst[sta(u)] + 1);
            else
                break;
        }
        while (!col[u.se].empty() && *prev(col[u.se].end()) > u.fi)
        {
            int cur = *col[u.se].lower_bound(u.fi);
            if (cur <= u.fi + lo[sta(u)])
                push(mp(cur, u.se), dst[sta(u)] + 1);
            else
                break;
        }
        while (!col[u.se].empty() && *col[u.se].begin() < u.fi)
        {
            int cur = *prev(col[u.se].lower_bound(u.fi));
            if (cur >= u.fi - hi[sta(u)])
                push(mp(cur, u.se), dst[sta(u)] + 1);
            else
                break;
        }
    }
    printf("-1");
}

int main()
{
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= n; j++)
            if (s[i][j] == '.')
            {
                row[i].insert(j);
                col[j].insert(i);
            }
    }
    init();
    scanf("%d %d %d %d", &st.fi, &st.se, &en.fi, &en.se);
    BFS();
}