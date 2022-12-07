#include <bits/stdc++.h>
using namespace std;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;

int n, m, it;
bool a[250][250];
int u[250][250];
int lx, ly, rx, ry, k;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void go (int vx, int vy)
{
    if (u[vx][vy])
        return;
    u[vx][vy] = it;
    lx = min (lx, vx);
    rx = max (rx, vx);
    ly = min (ly, vy);
    ry = max (ry, vy);
    k ++;
    for(int i = 0; i < 8; i ++)
    {
        int x = vx + dx[i];
        int y = vy + dy[i];
        if (0 <= x && x < n && 0 <= y && y < m)
            if (a[x][y] == 1)
                go (x, y);
    }
}

bool check1 (int x, int y)
{
    if (k < 4) return 0;
    if (rx - lx != ry - ly) return 0;
    int tmp = 0;
    for (int i = lx; i <= rx; i ++)
    {
        if (!u[i][ly] || !u[i][ry])
            return 0;
        tmp += 2;
    }
    for (int i = ly+1; i <= ry-1; i ++)
    {
        if (!u[lx][i] || !u[rx][i])
            return 0;
        tmp += 2;
    }
    if (tmp == k) return 1;
    else return 0;
}

bool check2 (int x, int y)
{
    if (k < 4) return 0;
    if (rx - lx != ry - ly) return 0;
    if (ry - y != y - ly) 	return 0;
    int tmp = 0;
    int x1 = x;
    int y1 = y;
    int x2 = lx + y - ly;
    int y2 = ly;
    for (int i = 0; i <= y - ly; i ++)
    {
        if (!u[x1+i][y1+i] || !u[x2+i][y2+i])
            return 0;
        tmp += 2;
    }
    tmp -= 4;
    x1 = x2;
    y1 = y2;
    x2 = rx;
    y2 = y;
    for (int i = 0; i <= y - ly; i ++)
    {
        if (!u[x1 - i][y1 + i] || !u[x2 - i][y2 + i]) return 0;
        tmp += 2;
    }
    if (tmp == k) return 1;
    else return 0;
}

void Work ()
{
    scanf ("%d%d", &n, &m);
    for(int i = 0; i < n; i ++)
   		for(int j = 0; j < m; j ++)
        {
            char ch;
            scanf (" %c", &ch);
            a[i][j] = ch == '1';
        }
    for(int i = 0; i < n; i ++)
   		for(int j = 0; j < m; j ++)
            u[i][j] = 0;
    it = 0;
    int res = 0;
    for(int i = 0; i < n; i ++)
   		for(int j = 0; j < m; j ++)
            if (a[i][j] && !u[i][j])
            {
                k = 0;
                it ++;
                lx = rx = i;
                ly = ry = j;
                go (i, j);
                if (check1 (i, j) || check2 (i, j))
                    res ++;
            }
    printf ("%d\n", res);
}

int main()
{
    int T;
    scanf ("%d", &T);
   	while(T --) Work();
    return 0;
}