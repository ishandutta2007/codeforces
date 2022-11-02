#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[1000001], n, m, f[2000001], v[2000001], test;
const int P = 1000000007;

long long rp(long long now, int k){
     long long will = 1;
     for (; k; k >>= 1, now *= now, now %= P)
          if (k & 1) will *= now, will %= P;
     return will;
}
     
int main(){
    // freopen("d.in", "r", stdin);
    // freopen("d.out", "w", stdout);
     scanf("%d", &n);
     memset(f, 0, sizeof(f));
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ++f[(1 << 20) - 1 - a[i]];
    // f[0] = 1;
    //for (int k = 1; k <= 100; k++) printf("%d %d\n", k, f[k]);
     for (int j = 1; j <= 20; j++)
     {
          memset(v,0,sizeof(v));
          for (int k = 0; k < 1 << 20; k++)
          {
               if ( k & ( 1<< (j - 1)) ) v[k] += f[k ^ (1 << (j - 1))], v[k] %= P; 
               else v[k] += f[k|(1 << (j - 1))],v[k] %= P, v[k] += f[k], v[k] %= P;
          }
          for (int k = 0; k < 1 << 20; k++) f[k] = v[k];
     }
     int ans = 0;
     for (int i = 0; i < 1 << 20; i++) 
     {
          int cnt = 0;
          for (int j = 0; j < 20; j++)
               if (i & (1 << j)) ++cnt;
          if (!(cnt & 1)) ans += rp(2, f[i]), ans %= P;
          else ans -= rp(2, f[i]), ans += P, ans %= P;
     }
     printf("%d\n", ans);
     //for (int j = 0; j <= 100; j++) printf("%d %d\n", j, f[j]);
}