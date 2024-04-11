#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct p
{
    int x, y;
    string path;
} cur;
const int dx[4] = {-1, 1, 0, 0},
          dy[4] = {0, 0, -1, 1};
int n, m, i, j, x, y;
string dir = "UDLR", path, field[105];
bool LR = 0, UD = 0, chk[105][105];

bool check(const int &x, const int &y)
{
    if (x < 1 || x > n)
        return 0;
    if (y < 1 || y > m)
        return 0;
    if (field[x][y] == '*')
        return 0;
    return 1;
}

void BFS()
{
    queue <p> q;
    q.push({1, 1, ""});
    chk[1][1] = 1;
    while (!q.empty())
    {
        cur = q.front();
        for (i = 0; i < 4; i++)
            if (check(cur.x + dx[i], cur.y + dy[i]) && !chk[cur.x + dx[i]][cur.y + dy[i]])
            {
                q.push({cur.x + dx[i], cur.y + dy[i], cur.path + (char)(i + '0')});
                chk[cur.x + dx[i]][cur.y + dy[i]] = 1;
                if (field[cur.x + dx[i]][cur.y + dy[i]] == 'F')
                {
                    path = cur.path + (char)(i + '0');
                    return;
                }
            }
        q.pop();
    }
}

void swapUD(int x, int y)
{
    UD = 1;
    int tmp_x, tmp_y;
    cout << "U\n";
    fflush(stdout);
    cin >> tmp_x >> tmp_y;
    if (tmp_x == x + 1 && tmp_y == y)
    {
        swap(dir[0], dir[1]);
        cout << "D\n";
        fflush(stdout);
        cin >> tmp_x >> tmp_y;
    }
}

void swapLR(int x, int y)
{
    LR = 1;
    int tmp_x, tmp_y;
    cout << "L\n";
    fflush(stdout);
    cin >> tmp_x >> tmp_y;
    if (tmp_x == x && tmp_y == y + 1)
    {
        swap(dir[2], dir[3]);
        cout << "R\n";
        fflush(stdout);
        cin >> tmp_x >> tmp_y;
    }
}

int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> field[i];
        field[i] = '.' + field[i];
    }
    BFS();
    x = 1; y = 1;
    for (i = 0; i < path.size(); i++)
    {
        if (path[i] < '2' && !UD)
            swapUD(x, y);
        if (path[i] > '1' && !LR)
            swapLR(x, y);
        cout << dir[path[i] - '0'] << '\n';
        fflush(stdout);
        cin >> x >> y;
    }
    return 0;
}