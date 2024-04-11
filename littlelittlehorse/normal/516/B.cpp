#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int D[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, cnt, tot, c[4000001][2], degree[2001][2001];
char str[2011][2011];

bool kill(int i, int j) {
     for (int k = 0; k < 4; k++) {
          int x = i + D[k][0], y = j + D[k][1];
          //printf("hhh %d %d\n", x, y);
          if (x < 1 || x > n || y < 1 || y > m) continue;
          if (str[x][y] == '.') 
               if (!--degree[x][y]) return false;
               else if (degree[x][y] == 1)
                    c[++tot][0] = x, c[tot][1] = y; 
          //printf("cut %d %d %d %d\n", x, y, tot, degree[x][y]);
     }
     return true;
}

int main() {
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++)
          scanf("%s", str[i] + 1);
     tot = 0;
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= m; j++) 
               if (str[i][j] == '.') {
                    ++cnt; degree[i][j] = 0;
                    for (int k = 0; k < 4; k++) {
                         int x = i + D[k][0], y = j + D[k][1];
                         if (x < 1 || x > n || y < 1 || y > m) continue;
                         if (str[x][y] == '.') ++degree[i][j];
                    }
                    if (degree[i][j] == 1) c[++tot][0] = i, c[tot][1] = j;
               }
     bool ans = true; int num = 0;
     for (int l = 1; l <= tot; l++) {
          int i = c[l][0], j = c[l][1];
          if (str[i][j] != '.') continue; 
          int x = c[l][0] - 1, y = c[l][1];
          if (x >= 1 && x <= n && str[x][y] == '.') {
               str[x][y] = '^'; str[i][j] = 'v'; num += 2;
               if (!kill(x, y)) {
                    ans = false;
                    break;
               }
               continue;
          }
          x = c[l][0] + 1, y = c[l][1];
          if (x >= 1 && x <= n && str[x][y] == '.') {
               str[x][y] = 'v'; str[i][j] = '^'; num += 2;
               if (!kill(x, y)) {
                    ans = false;
                    break;
               }
               continue;
          } 
          x = c[l][0], y = c[l][1] - 1;
          if (y >= 1 && y <= m && str[x][y] == '.') {
               str[x][y] = '<'; str[i][j] = '>'; num += 2;
               if (!kill(x, y)) {
                    ans = false;
                    break;
               }
               continue;
          }
          x = c[l][0], y = c[l][1] + 1;
          if (y >= 1 && y <= m && str[x][y] == '.') {
               str[x][y] = '>'; str[i][j] = '<'; num += 2;
               if (!kill(x, y)) {
                    ans = false;
                    break;
               }
               continue;
          }
     }
     if (ans && num == cnt) {
          for (int i = 1; i <= n; i++) printf("%s\n", str[i] + 1); 
     } else printf("Not unique\n");
}