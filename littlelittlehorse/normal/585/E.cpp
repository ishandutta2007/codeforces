#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int c[10000001], len, n, a[1000001], f[10000001], v[10000001], o[10000001], 
r[10000001];
bool b[10000001];
long long A, B;
const int p = 1000000007;

long long add(long long x, long long y) {
     return (x + y) % p;
}

long long dec(long long x, long long y) {
     x -= y;
     if (x < 0) x += p;
     return x;
}

long long mul(long long x, long long y) {
     return (x * y) % p;
}

long long rp(long long now, long long k) {
     long long will = 1;
     for (; k; k >>= 1, now *= now, now %= p) 
          if (k & 1) will *= now, will %= p;
     return will;
}

inline void gogo() {
     for (int i = 2; i <= 10000000; i++) if (v[i] && r[i]){
      //printf("%d %d %I64d %I64d %I64d\n", i, v[i], rp(2, v[i]) - 1, A, B); 
      if (r[i] & 1) A = add(A, rp(2, v[i]) - 1), B = add(B, mul(rp(2, v[i] - 1), v[i])); 
      else A = dec(A, rp(2, v[i]) - 1), B = dec(B, mul(rp(2, v[i] - 1), v[i]));
      //printf("%d %d %I64d %I64d\n", i, v[i], rp(2, v[i]) - 1, A, B); 
     }
}

long long gcd(long long a, long long b) {
     if (!b) return a;
     return gcd(b, a % b);
}
 
int main() {
     //freopen("e.in", "r", stdin);
     //freopen("e.out", "w", stdout);
     memset(b, false, sizeof(b)); b[1] = true; len = 0;
     memset(r, 0, sizeof(r));
     for (int i = 2; i <= 10000000; i++) {
          if (!b[i]) {
               c[++len] = i;
               r[i] = 1;
               o[i] = i;
          }
          for (int j = 1; j <= len && c[j] * i <= 10000000; j++) {
               b[i * c[j]] = true;
               if (!r[i]) r[i * c[j]] = 0;
               else if (c[j] == o[i]) r[i * c[j]] = 0;
                    else r[i * c[j]] = r[i] + 1, o[i * c[j]] = c[j];
               if (!(i % c[j])) break;
          }
     }
     //for (int i = 1; i <= 20; i++) printf("%d %d\n", i, r[i]);
     memset(f, 0, sizeof(f));
     scanf("%d", &n);
     int Gcd;
     for (int i = 1; i <= n; i++) {
          int x;
          scanf("%d", &x);
          ++f[x];
          if (i == 1) Gcd = x;
          else Gcd = gcd(Gcd, x);
     }
     if (Gcd != 1) {
          printf("0\n");
          return 0;
     }
     for (int i = 1; i <= 10000000; i++) {
          v[i] = 0;
          for (int j = i; j <= 10000000; j += i) {
               v[i] += f[j];
          }
     }
     A = 0; B = 0;
     gogo();
     swap(A, B);
    // printf("%I64d %I64d\n", A, B);
     B = mul(n, B);
     A = mul(A, 2);
     B = add(B, n);
     B = dec(B, A);
     printf("%I64d\n", B);
}