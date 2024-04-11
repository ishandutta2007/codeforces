#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[1000001][26], l, sg[1000001], c[1000001], dist[1000001];
char str[1000001];

int main(){
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     memset(a, 0, sizeof(a)); l = 0;
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++)
     {
          scanf("%s", str);
          int now = 0, len = strlen(str);
          for (int i = 0; i < len; i++)
          {
               if (!a[now][str[i] - 'a']) a[now][str[i] - 'a'] = ++l;
               now = a[now][str[i] - 'a'];
          }
     }    
     memset(dist, 0, sizeof(dist));
     dist[0] = 1; c[1] = 0; int k = 1;
     for (int l = 1; l <= k; l++)
     {
          int m = c[l];
          for (int i = 0; i < 26; i++)
               if (a[m][i]) c[++k] = a[m][i];
     }
     for (int i = k; i; --i)
     {
          int m = c[i]; bool ok = false;
          for (int j = 0; j < 26 && !ok; j++)
               if (a[m][j] && !sg[a[m][j]]) ok = true;
          if (ok) sg[m] = 1;
          else sg[m] = 0;
     }
     int status = 0;
     if (sg[0]) status = 1;
     for (int i = k; i; --i)
     {
          int m = c[i]; bool ok = false; int cnt = 0;
          for (int j = 0; j < 26 && !ok; j++)
               if (a[m][j]) 
               {
                    ++cnt;
                    if (!sg[a[m][j]]) ok = true;
               }
          if (!cnt) sg[m] = 1;
          else
          {
               if (ok) sg[m] = 1;
               else sg[m] = 0;
          }
     }
     if (sg[0]) status |= 2;
     if (status == 3) printf("First\n");
     else if (status == 1) 
               if (m & 1) printf("First\n"); else printf("Second\n");
          else printf("Second\n");
}