#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[51][51], v[1111111];
string str[51];
double C[21], cnt[101], D[21];
long long f[1111111];

int calc(long long now){
     if (!now) return 0;
     return calc(now >> 20) + v[now & ((1 << 20) - 1)];
}

int main(){
   //  freopen("c.in", "r", stdin);
   //  freopen("c.out", "w", stdout);
     for (int i = 0; i < 1 << 20; i++)
     {
          v[i] = 0;
          for (int j = 0; j < 20; j++)
               if (i & (1 << j)) ++v[i];
     }
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) cin >> str[i];
     int m = str[1].size();
     C[m] = m;
     for (int i = m - 1; i; --i) C[i] = C[i + 1] * i;
     D[0] = 1.0;
     for (int i = 1; i <= m; i++) D[i] = D[i - 1] * i;
     memset(f, 0, sizeof(f));
     for (int i = 1; i <= n; i++)
          for (int j = i + 1; j <= n; j++) 
          {
               int value = 0;
               for (int k = 0; k < m; k++)
                    if (str[i][k] == str[j][k]) value |= 1 << k;
               f[value] |= 1LL << (i - 1);
               f[value] |= 1LL << (j - 1);
          }
     for (int i = (1 << m) - 1; i >= 0; --i) 
          for (int j = 0; j < m; j++)
               if (!(i & (1 << j))) f[i] |= f[i | (1 << j)];
     memset(cnt, 0, sizeof(cnt));
     for (int i = 0; i < 1 << m; i++)
          for (int j = 0; j < m; j++)
               if (!(i & (1 << j))) cnt[v[i] + 1] += calc(f[i] - f[i | (1 << j)]);
     double ans = 0;
     for (int i = 1; i <= m; i++)
          ans += cnt[i] * D[i] / C[m - i + 1];
     printf("%.10f\n", ans / n);
}