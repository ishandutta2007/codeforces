#include <iostream>
using namespace std;


char f[25][25];
int cst[10];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int changeMask[25][25][4], takeMask[25][25][4];

int dist[25][25][300];
int n, m, k = 0;


struct Pos
{
    int x, y, mask;
    Pos() : x(), y(), mask() {}
    Pos(int x, int y, int take, int change) : x(x), y(y), mask(take | (change << k) ) {}
    int getX() {return x; }
    int getY() {return y; }
    int getTake() {return (mask & ( (1 << k) - 1) ); }
    int getChange() {return (mask >> k); }
    int getProfit()
    {
        int ans = 0;
        int tk = getTake();
        for (int i = 0; i < k; i++)
            if (tk & (1 << i) )
                ans += cst[i];
        return ans;
    }
};

Pos qu[1100100];
int l = 0, r = 0;

bool inf (int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m && f[x][y] == '.';
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", f[i] );
        for (int j = 0; j < m; j++)
            if (isdigit(f[i][j] ) )
                k++;
    }
    for (int i = 0; i < k; i++)
        scanf("%d", &cst[i] );
    int cur = 0;
    int sx, sy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (f[i][j] == 'B')
            {
                for (int h = i - 1; h >= 0; h--)
                {
                    if (j > 0)
                        changeMask[h][j - 1][1] |= (1 << cur);
                    changeMask[h][j][0] |= (1 << cur);
                }

                cur++;
            }
            if (isdigit(f[i][j] ))
            {
                int cur = f[i][j] - '1';
                for (int h = i - 1; h >= 0; h--)
                {
                    if (j > 0)
                        takeMask[h][j - 1][1] |= (1 << cur);
                    takeMask[h][j][0] |= (1 << cur);
                }
            }
            if (f[i][j] == 'S')
            {
                f[i][j] = '.';
                sx = i;
                sy = j;
            }
        }
    memset(dist, -1, sizeof dist);
    dist[sx][sy][0] = 0;
    qu[r++] = Pos(sx, sy, 0, 0);
    int ans = 0;
    while (r > l)
    {
        Pos p = qu[l++];
        int dst = dist[p.x][p.y][p.mask];
        int x = p.getX();
        int y = p.getY();
        int tk = p.getTake();
        int ch = p.getChange();

        if (ch == 0 && x == sx && y == sy)
        {
            int curans = p.getProfit() - dst;
            ans = max(ans, curans);
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!inf(nx, ny) )
                continue;
            int ntk = (tk ^ takeMask[x][y][d] );
            int nch = (ch ^ changeMask[x][y][d] );
            Pos np = Pos(nx, ny, ntk, nch);
            if (dist[np.x][np.y][np.mask] != -1)
                continue;
            qu[r++] = np;
            dist[np.x][np.y][np.mask] = dst + 1;
        }
    }
    printf("%d\n", ans);





    return 0;
}