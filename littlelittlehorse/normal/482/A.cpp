#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main(){
     //freopen("a.in", "r", stdin);
     //freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &m);
     int L = 1, R = n;
     for (int i = 1; i <= m; i++)
          if (i & 1) printf("%d ", L++);
          else printf("%d ", R--);
     if (m & 1) 
          for (int i = L; i <= R; i++) printf("%d ", i);
     else for (int i = R; i >= L; --i) printf("%d ", i);
     printf("\n");
}