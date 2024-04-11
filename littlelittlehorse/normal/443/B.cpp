#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

char str[201];
int n, m;

int main(){
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     int ans = 0;
     scanf("%s%d", str, &m);
     n = strlen(str); 
     for (int i = 0; i < n; i++)
          for (int j = 1; i + j + j <= n; j++)
          {
               bool ok = true;
               for (int k = i, l = i + j, x = 1; x <= j; x++, k++, l++)
                    if (str[k] != str[l])
                    {
                         ok = false;
                         break;
                    }
               if (ok) ans = max(ans, j + j);
          }
     for (int i = (m + n) / 2; i; --i)
     {
          bool ok = true;
          for (int j = m + n - i - 1, k = m + n - 1, l = 0; l < i; j--, k--, l++)
               if (j < n && k < n && str[j] != str[k])
               {
                    ok = false;
                    break;
               }
          if (ok) 
               ans = max(ans, i << 1);
     }
     printf("%d\n", ans);
}