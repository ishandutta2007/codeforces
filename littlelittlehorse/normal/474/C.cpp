#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[5][4][2], c[5][2], w[5][2], v[5][2];
bool b[5];

bool soso(int step){
    if (step == 5)
    {
        if (v[1][0] == v[2][0] && v[1][1] == v[2][1]) return false;
        if (v[3][0] + v[1][0] != v[2][0] + v[4][0]) return false;
        if (v[3][1] + v[1][1] != v[2][1] + v[4][1]) return false;
        int X1 = v[3][0] - v[1][0], Y1 = v[3][1] - v[1][1], 
            X2 = v[4][0] - v[2][0], Y2 = v[4][1] - v[2][1];
        if (X1 * X1 + Y1 * Y1 != X2 * X2 + Y2 * Y2) return false;
        if (X1 * X2 + Y1 * Y2) return false;
        return true;
    }
    for (int i = 1; i <= 4; i++)
        if (!b[i])
        {
            b[i] = true;
            v[step][0] = w[i][0]; v[step][1] = w[i][1];
            if (soso(step + 1)) return true;
            b[i] = false;
        }
    return false;
}
            
bool zheng(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4){
    w[1][0] = X1; w[1][1] = Y1;
    w[2][0] = X2; w[2][1] = Y2;
    w[3][0] = X3; w[3][1] = Y3;
    w[4][0] = X4; w[4][1] = Y4;
    memset(b, false, sizeof(b));
    return soso(1);
}

int main(){
//  freopen("a.in", "r", stdin);
//  freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (;n--;)
    {
        for (int i = 1; i <= 4; i++)
        {
            scanf("%d%d%d%d", &a[i][0][0], &a[i][0][1], &c[i][0], &c[i][1]);
            for (int j = 1; j < 4; j++)
            {
                int deltax = a[i][j - 1][0] - c[i][0], 
                    deltay = a[i][j - 1][1] - c[i][1];
                a[i][j][0] = c[i][0] - deltay;
                a[i][j][1] = c[i][1] + deltax;
            //  printf("%d %d %d %d\n", i, j, a[i][j][0], a[i][j][1]);
            }
        }
        int ans = 1 << 30;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    for (int l = 0; l < 4; l++)
                        if (zheng(a[1][i][0], a[1][i][1],
                                  a[2][j][0], a[2][j][1],
                                  a[3][k][0], a[3][k][1],
                                  a[4][l][0], a[4][l][1]))
                                  ans = min(ans, i + j + k + l);
        if (ans == 1 << 30) printf("-1\n");
        else printf("%d\n", ans);
    }
}