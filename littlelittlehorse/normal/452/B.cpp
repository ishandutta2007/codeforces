#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

double sqr(double now){ return now * now; }

int main(){
     //freopen("b.in", "r", stdin);
     //freopen("b.out", "w", stdout);
     scanf("%d%d", &n, &m);
     if (!n) 
     {
          printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, 0, m, 0, 0, 0, m - 1);
          return 0;
     }
     if (!m)
     {
          printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, 0, 0, 0, n - 1, 0);
          return 0;
     }
     if (n < m)
     {
          double ans1 = 2 * sqrt(sqr(n) + sqr(m)) + m,
                 ans2 = sqrt(sqr(n) + sqr(m)) + 2 * sqrt(sqr(n - 1) + sqr(m));
          if (ans1 > ans2) 
               printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 0, n, m, n, 0, 0, m);
          else printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, m, 0, 0, n - 1, m);
     }
     else
     {
          double ans1 = 2 * sqrt(sqr(n) + sqr(m)) + n,
                 ans2 = sqrt(sqr(n) + sqr(m)) + 2 * sqrt(sqr(m - 1) + sqr(n));
          if (ans1 > ans2) 
               printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 0, n, m, 0, m, n, 0);
          else printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, n, m, 0, 0, n, m - 1);
     }
}