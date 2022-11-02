#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int p, n;
bool b[1001];

int main(){
     scanf("%d%d", &p, &n);
     memset(b, false, sizeof(b));
     for (int i = 1; i <= n; i++)
     {
          int x;
          scanf("%d", &x);
          if (b[x % p])
          {
               printf("%d\n", i);
               return 0;
          }
          b[x % p] = true;
     }
     printf("-1\n");
}