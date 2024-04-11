#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int MX = 1E6 + 5;

int m, n, ans = 2, msk[MX];
bool vis[MX];
string s[MX];
queue<pair<int, int>> q;

int convert(int u, int v)
{
    return u * n + v;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> s[i];
    msk[convert(0, 0)] |= 1;
    for (q.push({0, 0}); !q.empty(); q.pop())
    {
        pair<int, int> cur = q.front();
        for (int i = 0; i < 2; i++)
            {
                int x = cur.fi + (i == 0), y = cur.se + (i == 1);
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if (s[x][y] == '#')
                    continue;
                if (msk[convert(x, y)] >> 0 & 1)
                    continue;
                msk[convert(x, y)] |= 1;
                q.push({x, y});
            }
    }
    msk[convert(m - 1, n - 1)] |= 2;
    for (q.push({m - 1, n - 1}); !q.empty(); q.pop())
    {
        pair<int, int> cur = q.front();
        for (int i = 0; i < 2; i++)
            {
                int x = cur.fi - (i == 0), y = cur.se - (i == 1);
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if (s[x][y] == '#')
                    continue;
                if (msk[convert(x, y)] >> 1 & 1)
                    continue;
                msk[convert(x, y)] |= 2;
                q.push({x, y});
            }
    }
    if (msk[convert(0, 0)] != 3)
        return cout << 0, 0;
    vis[convert(0, 0)] = 0;
    for (q.push({0, 0}); !q.empty(); q.pop())
    {
        pair<int, int> cur = q.front();
        if (q.size() == 1 && ((cur.fi > 0 || cur.se > 0) && (cur.fi < m - 1 || cur.se < n - 1)))
            return cout << 1, 0;
        for (int i = 0; i < 2; i++)
            {
                int x = cur.fi + (i == 0), y = cur.se + (i == 1);
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if (msk[convert(x, y)] != 3 || vis[convert(x, y)])
                    continue;
                vis[convert(x, y)] = true;
                q.push({x, y});
            }
    }
    cout << 2;
}