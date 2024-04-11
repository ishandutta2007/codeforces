#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, len, m, c[100001];
bool b[100001], v[100001];

inline void ex_gcd(int a, int b, long long &X1, long long &Y1){
     if (!b)
     {
          X1 = 1; Y1 = 0;
          return;
     }
     long long X2, Y2;
     ex_gcd(b, a % b, X2, Y2);
     X1 = Y2; Y1 = X2 - a / b * Y2;
}

int main(){
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     memset(b, false, sizeof(b));
     len = 0; b[1] = true;
     for (int i = 2; i <= 100000; i++)
     {
          if (!b[i]) c[++len] = i;
          for (int j = 1; j <= len; j++)
               if (i * c[j] > 100000) break;
               else
               {
                    b[i * c[j]] = true;
                    if (!(i % c[j])) break;
               }
     }
     scanf("%d", &n);
     if (n == 1)
     {
          printf("YES\n");
          printf("1\n");
          return 0;
     }
     if (n == 4)
     {
          printf("YES\n");
          printf("1 3 2 4\n");
          return 0;
     }
     if (b[n])
     {
          printf("NO\n");
          return 0;
     }
     c[1] = 1; c[n] = n;
     for (int i = 2; i < n; i++)
     {
         long long A, B;
         ex_gcd(i - 1, n, A, B);
         c[i] = A * i % n;
         if (c[i] < 0) c[i] += n;
     }
     printf("YES\n");
     for (int i = 1; i <= n; i++) 
     {
          printf("%d\n", c[i]);
     }
}