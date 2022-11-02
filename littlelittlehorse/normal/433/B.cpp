#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, Q, a[100001];
long long f[100001], v[100001];


int main(){
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
     f[0] = 0;
     for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
     sort(a + 1, a + n + 1);
     v[0] = 0;
     for (int i = 1; i <= n; i++) v[i] = v[i - 1] + a[i];
     scanf("%d", &Q);
     for (;Q--;)
     {
          int type, x, y;
          scanf("%d%d%d", &type, &x, &y);
          if (type == 1) printf("%I64d\n", f[y] - f[x - 1]);
          else printf("%I64d\n", v[y] - v[x - 1]);
     }
}