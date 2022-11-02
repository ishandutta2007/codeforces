#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

long long f[100001][2];
int n, a[100001];

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d", &n);
     memset(a, 0, sizeof(a));
     for (int i = 1; i <= n; i++)
     {
          int x;
          scanf("%d", &x);
          ++a[x];
     }
     memset(f, 0, sizeof(f));
     f[0][0] = 0;
     for (int i = 1; i <= 100000; i++) 
          f[i][0] = max(f[i - 1][0], f[i - 1][1]),
          f[i][1] = f[i - 1][0] + 1LL * i * a[i];
     printf("%I64d\n", max(f[100000][0], f[100000][1]));
}