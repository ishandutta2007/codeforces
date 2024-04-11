#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a2, a3, a5, a7;
char str[101];

inline void down(char str) {
     int i = str - '0';
     for (int j = 2; j <= i; j++) {
          int sx = j;
          for (; !(sx % 2); sx /= 2) ++a2;
          for (; !(sx % 3); sx /= 3) ++a3;
          for (; !(sx % 5); sx /= 5) ++a5;
          for (; !(sx % 7); sx /= 7) ++a7;
     }
}

int main() {
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     a2 = a3 = a5 = a7 = 0;
     scanf("%d%s", &n, str);
     for (int i = 0; i < n; i++)
          down(str[i]);
     for (int i = 1; i <= a7; i++)
          printf("7");
     a5 -= a7; a3 -= a7 * 2; a2 -= a7 * 4;
     for (int i = 1; i <= a5; i++)
          printf("5");
     a3 -= a5; a2 -= a5 * 3;
     for (int i = 1; i <= a3; i++)
          printf("3");
     a2 -= a3;
     for (int i = 1; i <= a2; i++)
          printf("2");
     printf("\n");
}