#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, init, end, m, f[5011], v[5011];
const int P = 1000000007;

inline void add(int &x, int y){
     x += y;
     if (x >= P) x -= P;
}

inline void dec(int &x, int y){
     x -= y;
     if (x < 0) x += P;
}

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d%d%d%d", &n, &init, &end, &m);
     memset(f, 0, sizeof(f));
     f[init] = 1;
     for (int i = 1; i <= m; i++)
     {
          memset(v, 0, sizeof(v));
          for (int j = 1; j <= n; j++)
          {
               int gap = abs(j - end) - 1,
               L = max(1, j - gap), R = min(j + gap, n);
               if (L > R) continue;
               add(v[L], f[j]); dec(v[R + 1], f[j]);
               dec(v[j], f[j]); add(v[j + 1], f[j]);
          }
          for (int j = 1; j <= n; j++) add(v[j], v[j - 1]);
          memcpy(f, v, sizeof(f));
     }
     int ans = 0;
     for (int i = 1; i <= n; i++) add(ans, f[i]);
     printf("%d\n", ans);
}