#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 405;
const int Maxv = 20;
const int nil = 200;

int x, y, n, d;
int vx[Maxv], vy[Maxv];
int win[Maxn][Maxn][2][2];

int canWin(int x, int y, int t1, int t2)
{
    if ((x - nil) * (x - nil) + (y - nil) * (y - nil) > d * d) return 1;
    if (!win[x][y][t1][t2]) {
                            int opp = 1;
                            for (int i = 0; i < n && opp == 1; i++)
                                opp = min(opp, canWin(x + vx[i], y + vy[i], t2, t1));
                            if (t1 == 0) opp = min(opp, canWin(y, x, t2, 1));
                            win[x][y][t1][t2] = -opp;
    }
    return win[x][y][t1][t2];
}

int main()
{
    cin >> x >> y >> n >> d;
    for (int i = 0; i < n; i++) cin >> vx[i] >> vy[i];
    if (canWin(x + nil, y + nil, 0, 0) == 1) cout << "Anton\n";
    else cout << "Dasha\n";
    return 0;
}