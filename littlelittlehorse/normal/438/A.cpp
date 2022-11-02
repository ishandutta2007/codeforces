#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, v[1001];

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &m);
     for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
     int ans = 0;
     for (int i = 1; i <= m; i++)
     {
          int x, y;
          scanf("%d%d", &x, &y);
          ans += min(v[x], v[y]);
     }
     printf("%d\n", ans);
}