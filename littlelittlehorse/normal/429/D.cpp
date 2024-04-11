#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001], v[100001], f[100001];
long long  ans;

int main(){
     //freopen("d.in", "r", stdin);
     //freopen("d.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v[i] = (long long)i * i;
     f[0] = 0;
     for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
     memset(v, 127, sizeof(v));
     //
     for (int i = 1; i <= n; i++)
          for (int j = i - 1, k = 1; j && k <= 10011; --j, ++k)
               v[k] = min(v[k], abs(f[i] - f[j]));
     ans = 1LL << 60LL;
     for (int i = 1; i <= 10011; i++)  
          if (v[i] < 1 << 30) ans = min(ans, i * i + (long long)v[i] * v[i]);
     printf("%I64d\n", ans);
}