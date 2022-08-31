#include <iostream>
using namespace std;


char f[45][45];

int good[45][45][45][45];
int n, m, q;


bool inx(int x, int n)
{
    return x >= 0 && x < n;
}
bool inf(int a, int b, int c, int d)
{
    return inx(a, n) && inx(c, n) && a <= c && inx(b, m) && inx(d, m) && b <= d;
}

void add(int a, int b, int c, int d, int val)
{
    if (inf(a, b, c, d) )
        good[a][b][c][d] += val;
}
int sgn[4] = {-1, -1, 1, 1};
int val[16];

int bit(int m, int i)
{
    return ( (m >> i) & 1);
}

int main()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
            val[i] ^= bit(i, j);
        if (val[i] == 0)
            val[i] = -1;
    }
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%s", f[i] );
    for (int a = 0; a < n; a++)
        for (int c = a; c < n; c++)
        {
            for (int b = 0; b < m; b++)
                for (int d = b; d < m; d++)
                {
                    bool gd = true;
                    for (int i = a; i <= c; i++)
                        if (f[i][d] != '0')
                            gd = false;
                    if (!gd)
                        break;
                    good[a][b][c][d] = 1;
                }
        }
    for (int da = 0; da < n; da++)
        for (int db = 0; db < m; db++)
        {
            for (int a = 0; a < n; a++)
                for (int b = 0; b < m; b++)
                {
                    int c = a + da;
                    int d = b + db;
                    int cgood = good[a][b][c][d];
                    for (int mask = 1; mask < 16; mask++)
                    {
                        int num = val[mask];
                        int na = sgn[0] * bit(mask, 0) + a;
                        int nb = sgn[1] * bit(mask, 1) + b;
                        int nc = sgn[2] * bit(mask, 2) + c;
                        int nd = sgn[3] * bit(mask, 3) + d;
                        add(na, nb, nc, nd, num * cgood);
                    }
                }
        }
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", good[a - 1][b - 1][c - 1][d - 1] );
    }

    return 0;
}