#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, m;
char str[1101];

int main(){
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
     scanf("%d%d", &n, &m);
     scanf("%s", str + 1); n = strlen(str + 1);
     bool ok = false;
     for (int i = n; i && !ok; --i)
          for (int j = str[i] - 'a' + 1; j < m && !ok; j++)
          {
               bool work = true;
               if (i != 1 && j == str[i - 1] - 'a') work = false;
               if (i > 2 && j == str[i - 2] - 'a') work = false;
               if (!work) continue;
               str[i] = j + 'a';
               for (int k = i + 1; k <= n; k++)
                    for (int l = 0; l < m; l++) 
                    {
                         bool can = true;
                         if (k != 1 && l == str[k - 1] - 'a') can = false;
                         if (k > 2 && l == str[k - 2] - 'a') can = false;
                         if (can) 
                         {
                              str[k] = l + 'a';
                              break;
                         }
                    }
               printf("%s\n", str + 1);
               ok = true;
          }
     if (!ok) printf("NO\n");
}