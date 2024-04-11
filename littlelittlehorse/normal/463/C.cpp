#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[2001][2001], position[2][2];
long long zs[2001][2001], ys[2001][2001], zx[2001][2001], yx[2001][2001], Max[2];

bool inside(int x, int y){
     return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main(){
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
               scanf("%d", &a[i][j]);
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
               zs[i][j] = (inside(i - 1, j - 1) ? zs[i - 1][j - 1] : 0) + a[i][j],
               ys[i][j] = (inside(i - 1, j + 1) ? ys[i - 1][j + 1] : 0) + a[i][j];
     for (int i = n; i >= 1; i--)
          for (int j = 1; j <= n; j++)
               zx[i][j] = (inside(i + 1, j - 1) ? zx[i + 1][j - 1] : 0) + a[i][j],
               yx[i][j] = (inside(i + 1, j + 1) ? yx[i + 1][j + 1] : 0) + a[i][j];
     memset(Max, 128, sizeof(Max));
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
          {
               long long value = zx[i][j] + zs[i][j] + yx[i][j] + ys[i][j] - 3LL * a[i][j];
               if (value > Max[(i + j) & 1])
                    Max[(i + j) & 1] = value, 
                    position[(i + j) & 1][0] = i,
                    position[(i + j) & 1][1] = j;
          }
     printf("%I64d\n%d %d %d %d\n", Max[0] + Max[1], position[0][0], position[0][1], position[1][0], position[1][1]);
}