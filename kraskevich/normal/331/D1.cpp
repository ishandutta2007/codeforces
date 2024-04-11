#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <string.h>
#include <cctype>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;


//-----TEMPLATE STARTS HERE------//
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef long double LD;

#define MP make_pair
#define PB push_back
#define hash __hash__
#define left __left__
#define right __right__
#define link __link__
#define div __div__
#define next __next__
#define y0 y1005000
#define y1 y1005001
#define F first
#define S second
//-----TEMPLATE ENDS HERE------//
//--ACTUAL SOLUTION IS BELOW---//

const int N = 33;

map<char, int> dd;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int id[N][N];
int x0[N], y0[N], x1[N], y1[N];
bool u[N][N][4];
PII par[N][N][4];
int pod[N][N][4];
int b, n;
LL t;
int resx;
int resy;

int f(int vx, int vy)
{
    for (int i = 0; i < 4; i++)
        if (dx[i] == vx && dy[i] == vy)
            return i;
}

void dfs(int x, int y, int vx, int vy)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            for (int d = 0; d < 4; d++)
                u[i][j][d] = false;
    int ox = -1, oy = -1;
    int od = 0;
    for (;;)
    {
        if (t == 0)
        {
            resx = x;
            resy = y;
            return;
        }
        if (id[x][y] >= 0)
        {
            vx = dx[id[x][y]];
            vy = dy[id[x][y]];
        }
        int dir = f(vx, vy);
        par[x][y][dir] = PII(ox, oy);
        pod[x][y][dir] = od;
        od = dir;
        ox = x;
        oy = y;
        if (u[x][y][dir])
        {
            vector<PII> c;
            PII v = par[x][y][dir];
            int d = pod[x][y][dir];
            while (v != PII(x, y) || d != dir)
            {
                c.PB(v);
                int xx = v.F;
                int yy = v.S;
                v = par[xx][yy][d];
                d = pod[xx][yy][d];
            }
            c.PB(PII(x, y));
            reverse(c.begin(), c.end());
            LL l = c.size();
            t %= l;
            resx = c[t].F;
            resy = c[t].S;
            return;
        }
        else
        {
            u[x][y][dir] = true;
            x = x + vx;
            y = y + vy;
            if (x < 0 || x > n || y < 0 || y > n)
            {
                resx = ox;
                resy = oy;
                return;
            }
            t--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        freopen("out.cpp", "w", stdout);
    #endif

    dd['U'] = 0;
    dd['D'] = 1;
    dd['R'] = 2;
    dd['L'] = 3;

    cin >> b >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            id[i][j] = -1;
    for (int i = 0; i < b; i++)
    {
        cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
        int cd = 0;
        if (x0[i] == x1[i])
        {
            if (y0[i] < y1[i])
                cd = 0;
            else
                cd = 1;
        }
        if (y0[i] == y1[i])
        {
            if (x0[i] < x1[i])
                cd = 2;
            else
                cd = 3;
        }
        for (int xx = min(x0[i], x1[i]); xx <= max(x0[i], x1[i]); xx++)
            for (int yy = min(y0[i], y1[i]); yy <= max(y0[i], y1[i]); yy++)
                id[xx][yy] = cd;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        cin >> t;
        dfs(x, y, dx[dd[c]], dy[dd[c]]);
        cout << resx << " " << resy << endl;
    }


    return 0;
}