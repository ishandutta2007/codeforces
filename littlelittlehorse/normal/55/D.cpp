#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test, lcm[512], c[19], v[19], len, r[48][48];
long long f[19][51][2521], L, R, t[19];
vector<int> a[19][521];

int gcd(int a, int b) {
     if (!b) return a;
     return gcd(b, a % b);
}

int LCM(int a, int b) { 
     return a * b / gcd(a, b);
}

int code(int i, int j, int k, int l) {
     return i * 12 + j * 4 + k * 2 + l;
}

int tog(int a, int b) {
     int two = a / 12, three = (a / 4) % 3, five = (a / 2) % 2, seven = a % 2;
     int twox = b / 12, threex = (b / 4) % 3, fivex = (b / 2) % 2, sevenx = b % 2;
     return code(max(two, twox), max(three, threex), max(five, fivex), max(seven, sevenx));
}              

long long calc(long long now) {
     len = 0;
     for (; now; now /= 10) c[++len] = now % 10;
     for (int i = 1, j = len; i < j; i++, j--) swap(c[i], c[j]);
     long long ans = 0, value = 0; int status = 0; 
     for (int i = 1; i <= len; i++) {
          for (int j = 0; j < c[i]; j++) {
               int aim = status;
               int two = aim / 12, three = (aim / 4) % 3, five = (aim / 2) % 2, seven = aim % 2;
               if (j == 2) two = max(two, 1);
               if (j == 3) three = max(three, 1);
               if (j == 4) two = max(two, 2);
               if (j == 5) five = max(five, 1);
               if (j == 6) two = max(two, 1), three = max(three, 1);
               if (j == 7) seven = max(seven, 1);
               if (j == 8) two = max(two, 3);
               if (j == 9) three = max(three, 2);
               aim = code(two, three, five, seven);
               for (int k = 0; k < 48; k++)
                    for (int l = 0; l < 2520; l++) 
                         if (f[len - i][k][l]) {
                         //printf("%d %d %d %d\n", i, k, l, aim);
                         int num = ((value * 10 + j) * t[len - i] + l) % 2520;
                         if (!(num % lcm[r[k][aim]])) ans += f[len - i][k][l];
                    }
          }
          value = value * 10 + c[i];
          int two = status / 12, three = (status / 4) % 3, five = (status / 2) % 2, seven = status % 2;
          if (c[i] == 2) two = max(two, 1);
          if (c[i] == 3) three = max(three, 1);
          if (c[i] == 4) two = max(two, 2);
          if (c[i] == 5) five = max(five, 1);
          if (c[i] == 6) two = max(two, 1), three = max(three, 1);
          if (c[i] == 7) seven = max(seven, 1);
          if (c[i] == 8) two = max(two, 3);
          if (c[i] == 9) three = max(three, 2);
          status = code(two, three, five, seven);
     }
     //printf("%I64d\n", ans);
     return ans;
}

int main() {
    // freopen("55d.in", "r", stdin);
    // freopen("55d.out", "w", stdout);
     t[0] = 1;
     for (int i = 1; i <= 18; i++) t[i] = t[i - 1] * 10;
     memset(lcm, 0, sizeof(lcm));
     lcm[0] = 1;
     for (int i = 0; i < 48; i++)
          for (int j = 0; j < 48; j++) r[i][j] = tog(i, j);
     for (int i = 1; i < 48; i++) {
          int two = i / 12, three = (i / 4) % 3, five = (i / 2) % 2, seven = i % 2;
          lcm[i] = 1;
          for (int j = 0; j < two; j++) lcm[i] *= 2;
          for (int j = 0; j < three; j++) lcm[i] *= 3;
          for (int j = 0; j < five; j++) lcm[i] *= 5;
          for (int j = 0; j < seven; j++) lcm[i] *= 7;
     } 
     memset(f, 0, sizeof(f));
     f[0][0][0] = 1;
     for (int i = 0; i < 18; i++) 
          for (int j = 0; j < 48; j++)
               for (int k = 0; k < 2520; k++) 
                    if (f[i][j][k]) {
                         int two = j / 12, three = (j / 4) % 3, five = (j / 2) % 2, seven = j % 2;
                         for (int l = 0; l < 10; l++) {
                              if (!l || l == 1) f[i + 1][j][(k * 10 + l) % 2520] += f[i][j][k];
                              if (l == 2 || l == 4 || l == 8) 
                                   f[i + 1][code(max(two, l == 2 ? 1 : l == 4 ? 2 : 3), three, five, seven)][(k * 10 + l) % 2520] += f[i][j][k];
                              if (l == 3 || l == 9) 
                                   f[i + 1][code(two, max(three, l == 3 ? 1 : 2), five, seven)][(k * 10 + l) % 2520] += f[i][j][k];
                              if (l == 6) 
                                   f[i + 1][code(max(1, two), max(1, three), five, seven)][(k * 10 + l) % 2520] += f[i][j][k];
                              if (l == 5) f[i + 1][code(two, three, max(1, five), seven)][(k * 10 + l) % 2520] += f[i][j][k];
                              if (l == 7) f[i + 1][code(two, three, five, max(1, seven))][(k * 10 + l) % 2520] += f[i][j][k];
                         }
                    }
     scanf("%d", &test);
     for (; test--; ) {
          scanf("%I64d%I64d", &L, &R);
          printf("%I64d\n", calc(R + 1) - calc(L));
     }               
}