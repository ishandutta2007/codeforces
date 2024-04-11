#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int Left = 1, n, k, a[10001][4], num, f[10001];
bool b[1000001];

int gf(int i){
     if (i == f[i]) return i;
     return f[i] = gf(f[i]);
}

int gcd(int a, int b){
     if (!b) return a;
     return gcd(b, a % b);
}

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &k);
     a[1][0] = 1; a[1][1] = 2; a[1][2] = 3; a[1][3] = 5;
     for (int i = 2; i <= n; i++)
          for (int j = 0; j < 4; j++)
               a[i][j] = a[i - 1][j] + 6;
     printf("%d\n", a[n][3] * k);
     for (int i = 1; i <= n; i++)
     {
          for (int j = 0; j <= 3; j++)
          {
               printf("%d", a[i][j] * k);
               if (j != 4) printf(" ");
          }
          printf("\n");
     }
}