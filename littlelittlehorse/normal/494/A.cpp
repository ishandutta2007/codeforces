#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, a[1000001];
char str[111111];

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%s", str);
     n = strlen(str); m = 0; k = 0;
     for (int i = 0; i < n; i++) 
          if (str[i] == '(') ++m;
          else if (str[i] == ')') --m;
          else ++k;
     if (m < k) 
     {
          printf("-1\n");
          return 0;
     }
     int Sx = k;
     int len = 0;
     for (int i = 0; i < n; i++)
          if (str[i] == '(') a[++len] = '(';
          else if (str[i] == ')') a[++len] = ')';
          else if (k != 1) --k, --m, a[++len] = ')';
          else for (int i = 1; i <= m; i++) a[++len] = ')';
     int r = 0;
     for (int i = 1; i <= len; i++)
     {
          if (a[i] == '(') ++r;
          else --r;
          if (r < 0) 
          {
               printf("-1\n");
               return 0;
          }
     }
     for (int i = 1; i < Sx; i++) printf("1\n");
     printf("%d\n", m);
}