#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int p = 1000000007;
long long C[4001][4001], f[4001][2];
int ans, n;

inline void add(long long &a, long long b) {
     a += b;
     if (a >= p) a -= p;
}

long long rp(long long now, int k) {
     long long will = 1;
     for (; k; k >>= 1, now *= now, now %= p)
          if (k & 1) will *= now, will %= p;
     return will;
}
  
int calc(int m) {
     return C[n][m] * rp(2, (n - m) * (n - m + 1) / 2) % p;
}


int main() {
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     memset(C, 0, sizeof(C));
     C[0][0] = 1;
     for (int i = 1; i <= 4000; i++) {
          C[i][0] = 1;
          for (int j = 1; j <= i; j++) 
               C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
     }
     memset(f, 0, sizeof(f));
     f[0][0] = 1;
     for (int i = 1; i <= 4000; i++) {
          f[i][1] = (f[i - 1][0] + f[i - 1][1]) % p;
          for (int j = 0; j < i; j++)
               add(f[i][1], f[i - 1 - j][1] * C[i - 1][j] % p),
               add(f[i][0], f[i - 1 - j][0] * C[i - 1][j] % p);
     }
     scanf("%d", &n);
     printf("%I64d\n", f[n][1]);
}