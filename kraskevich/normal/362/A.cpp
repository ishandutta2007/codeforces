#include <bits/stdc++.h>

using namespace std;

const int dx[] = {2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2};

string field[8];
bool u[8][8][8][8];
bool good;

void dfs(int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
        return;
    if (x1 >= 8 || y1 >= 8 || x2 >= 8 || y2 >= 8)
        return;
    if (u[x1][y1][x2][y2])
        return;
    u[x1][y1][x2][y2] = true;
    if (field[x1][y1] != '#' && x1 == x2 && y1 == y2)
        good = true;
    for (int dir1 = 0; dir1 < 4; dir1++)
        for (int dir2 = 0; dir2 < 4; dir2++)
            dfs(x1 + dx[dir1], y1 + dy[dir1], x2 + dx[dir2], y2 + dy[dir2]);
}

void solve()
{
    for (int i = 0; i < 8; i++)
        cin >> field[i];
    memset(u, 0, sizeof u);
    good = false;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++)
                for (int t = 0; t < 8; t++)
                    if ((k != i || j != t) && field[i][j] == 'K' && field[k][t] == 'K')
                        dfs(i, j, k, t);
    if (good)
        cout << "YES";
    else
        cout << "NO";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}