#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

int n, c[100001], step;
int f[111][100001];
deque<int> a[100001];
     
int main(){
    // freopen("c.in", "r", stdin);
    // freopen("c.out", "w", stdout);
     scanf("%d", &n);  step = 1000;
     for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
     for (int i = 1, k = 1; i <= n; i += step, k++)
     {
          int j = min(i + step - 1, n);
          a[k].clear();
          memset(f[k], 0, sizeof(f[k])); 
          for (int l = i; l <= j; l++) a[k].push_back(c[l]), ++f[k][c[l]];
     }
     int m;
     scanf("%d", &m);
     int last = 0;
     for (;m--;)
     {
          int x, y, z;
          int type;
          scanf("%d", &type);
          if (type == 1)
          {
               scanf("%d%d", &x, &y);
               x = (x + last - 1) % n + 1;
               y = (y + last - 1) % n + 1;
               if (x > y) swap(x, y);
               int L = (x - 1) / step + 1, R = (y - 1) / step + 1;
               if (L == R)
               {
                    int value = a[R][(y - 1) % step];
                   // printf("%d\n", value);
                    for (int i = (y - 1) % step - 1; i >= (x - 1) % step; i--)
                         a[R][i + 1] = a[R][i];
                    a[R][(x - 1) % step] = value;
               }
               else
               {
                    int Q = a[L][step - 1]; --f[L][Q];
                    for (int i = step * L - 1; i >= x; i--) 
                         a[L][(i - 1) % step + 1] = a[L][(i - 1) % step];
                    a[L][(x - 1) % step] = a[R][(y - 1) % step];
                    ++f[L][a[L][(x - 1) % step]];
                     --f[R][a[L][(x - 1) % step]];
                    for (int i = L + 1; i <= R - 1; i++)
                    {
                         int what = a[i][step - 1];
                    //  printf("huobuxiaqule %d\n", Q);
                         a[i].push_front(Q); ++f[i][Q]; Q = what; --f[i][Q];
                    //  printf("zhendehuobuxiaqule %d\n", Q);
                         a[i].pop_back();
                    }
                    //printf("memeda %d\n", Q);
                    ++f[R][Q];
                    for (int i = 0; i <= (y - 1) % step; i++) 
                    {
                         int P = a[R][i];
                         a[R][i] = Q; Q = P;
                    }
               }     
          }
          else
          {
               scanf("%d%d%d", &x, &y, &z);
               x = (x + last - 1) % n + 1;
               y = (y + last - 1) % n + 1;
               z = (z + last - 1) % n + 1;
               if (x > y) swap(x, y);
              // printf("www %d %d %d\n", x, y, z);
               int L = (x - 1) / step + 1, R = (y - 1) / step + 1, ans = 0;
            //   printf("%d %d %d\n", x, y, z);
               if (L == R)
               {
                    for (int i = (x - 1) % step; i <= (y - 1) % step; i++)
                    {
                         if (a[L][i] == z) ++ans;
                        // printf("%d\n", a[L][i]);
                    }
                    printf("%d\n", last = ans);
               }
               else
               {
                    //printf("dhh %d %d\n", x, step * L);
                    for (int i = x; i <= step * L; i++) 
                         if (a[L][(i - 1) % step] == z) ++ans;
                    //printf("%d %d\n", L + 1, R - 1);
                    for (int i = L + 1; i <= R - 1; i++) ans += f[i][z];
                    for (int i = 0; i <= (y - 1) % step; i++) 
                         if (a[R][i] == z) ++ans;
                    printf("%d\n", last = ans);
               }     
          }
     }
}