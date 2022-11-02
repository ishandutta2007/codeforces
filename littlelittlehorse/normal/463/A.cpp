#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, s, ans = -1;

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &s); s *= 100;
     for (int i = 1; i <= n; i++)
     {
          int x, y;
          scanf("%d%d", &x, &y);
          x *= 100; x += y;
          if (x <= s) ans = max(ans, (100 - y) % 100);
     }
     printf("%d\n", ans);
}