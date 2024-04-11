#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
     int x, y;
     bool operator < (const node &A) const{
          if (x != A.x) return x < A.x;
          return y < A.y;
     }
} a[5001];
int n, m;

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
     sort(a + 1, a + n + 1);
     int num = 0;
     for (int i = 1; i <= n; i++)
          if (a[i].y < num) num = a[i].x; else num = a[i].y;
     printf("%d\n", num);
}