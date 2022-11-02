#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1000001];
long long f[1000001], value;

int main(){
   //  freopen("d.in", "r", stdin);
   //  freopen("d.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
     if (n == 1)
     {
          printf("%d\n", a[1]);
          return 0;
     }
     value = -(1LL << 60LL); f[0] = 0; int status = 3;
     for (int i = 1; i <= n; i++)
     {
          if (status == 1) f[i] = max(f[i - 1], value + a[i]);
          else if (status == 2) f[i] = max(f[i - 1], value - a[i]);
          if (i != n)
          if (a[i] <= a[i + 1]) 
          {
               if (status & 1) value = max(f[i - 1] - a[i], value);
               else value = f[i - 1] - a[i];
               status = 1;
          }
          else 
          {
               if (status & 2) value = max(f[i - 1] + a[i], value);
               else value = f[i - 1] + a[i];
               status = 2;
          }
     }
     printf("%I64d\n", f[n]);
}