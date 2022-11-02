#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, Dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
char str[101][101];

bool check(int x, int y){
     if (x < 0 || x >= n || y < 0 || y >= n) return false;
     return str[x][y] == 'o';
}

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%s", str[i]);
     for (int i = 0; i < n; i++)
          for (int j = 0; j < n; j++)
          {
               int cnt = 0;
               for (int k = 0; k < 4; k++)
                    if (check(i + Dir[k][0], j + Dir[k][1])) ++cnt;
               if (cnt & 1)
               {
                    printf("NO\n");
                    return 0;
               }
          }
     printf("YES\n");
}