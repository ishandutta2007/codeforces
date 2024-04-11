#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main(){
     //freopen("c.in", "r", stdin);
     //freopen("c.out", "w", stdout);
     scanf("%d", &n);
     for (int i = n / 7; i >= 0; --i)
          if ( !((n - i * 7) % 4) )
          {
               int j = (n - i * 7) / 4;
               for (int k = 1; k <= j; k++) printf("4");
               for (int k = 1; k <= i; k++) printf("7");
               printf("\n");
               return 0;
          }
     printf("-1\n");
}