#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int m = 1000000;
int n, a[1000001];
bool b[1000001];

int main(){
  //   freopen("b.in", "r", stdin);
  //   freopen("b.out", "w", stdout);
     scanf("%d", &n);
     memset(b, false, sizeof(b));
     for (int i = 1; i <= n; i++)
     {
          int x;
          scanf("%d", &x);
          b[x] = true;
     }
     int last = 0;
     for (int i = 1; i <= m; i++) 
     {
          if (b[i]) last = i;
          a[i] = last;
     }
     int ans = 0;
     for (int i = 1; i <= m; i++)
          if (b[i])
          for (int l = i, r = i + i - 1; l <= m; l += i, r += i)
          {
               r = min(r, m);
               if (a[r] >= l) ans = max(ans, a[r] - l);
          }
     printf("%d\n", ans);
}