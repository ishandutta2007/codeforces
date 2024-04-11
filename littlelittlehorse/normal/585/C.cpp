#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001];
long long x, y;

long long gcd(long long a, long long b) {
     if (!b) return a;
     return gcd(b, a % b);
}

void work(long long a, long long b, int status) {
     if (b == 1) {
          if (a == 1) return;
          if (!status) printf("%I64dA", a - 1);
          else printf("%I64dB", a - 1);
          return;
     }
     printf("%I64d", a / b);
     if (!status) printf("A");
     else printf("B");
     work(b, a % b, 1 - status);
}

int main() {
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     scanf("%I64d%I64d", &x, &y);
     if (gcd(x, y) != 1) {
          printf("Impossible\n");
          return 0;
     }
     n = 0;
     if (x > y) work(x, y, 0);
     else work(y, x, 1);
}