#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt1, cnt2;

int main(){
   // freopen("a.in", "r", stdin);
   // freopen("a.out", "w", stdout);
    scanf("%d", &n); cnt1 = cnt2 = 0;
    for (int i = 1; i <= n; i++)
    {
          int x;
          scanf("%d", &x);
          if (x == 100) ++cnt1; else ++cnt2;
    }
    if (cnt1 & 1) 
    {
          printf("NO\n");
          return 0;
    }
    int avg = (cnt1 + cnt2 * 2) / 2;
    for (int i = 0; i <= avg && i <= cnt1; i++)
          if (!((avg - i) & 1) && (avg - i) / 2 <= cnt2)
          {
               printf("YES\n");
               return 0;
          }
    printf("NO\n");
}