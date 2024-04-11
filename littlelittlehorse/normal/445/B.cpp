#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[51], n, m;
long long ans;

int gf(int i){
     if (i == f[i]) return i;
     return f[i] = gf(f[i]);
}

int main(){
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) f[i] = i;
     ans = 1;
     for (int i = 1; i <= m; i++)
     {
          int x, y;
          scanf("%d%d", &x, &y);
          if (gf(x) != gf(y))
               f[gf(x)] = gf(y), ans <<= 1;
     }
     printf("%I64d\n", ans);
}