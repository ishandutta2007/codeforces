#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
char str[101][101];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", str[i]);
    for (int i = 0; i < n; i++)
    {
          for (int j = 0; j < m; j++)
               if (str[i][j] == '-') printf("-");
               else if ((i + j) & 1) printf("B");
               else printf("W");
          printf("\n");
     }
}