#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m, x, y, a[100001];
set<int> events;

int main(){
   //  freopen("a.in", "r", stdin);
   //  freopen("a.out", "w", stdout);
     scanf("%d%d%d%d", &n, &m, &x, &y); events.clear();
     for (int i = 1; i <= n; i++) scanf("%d", &a[i]), events.insert(a[i]);
     int status = 0;
     for (int i = 1; i <= n; i++) 
     {
          int z = a[i] - x;
          if (z > 0 && events.find(z) != events.end()) status |= 1;
          
          z = a[i] + x;
          if (z <= m && events.find(z) != events.end()) status |= 1;
          
          z = a[i] - y;
          if (z > 0 && events.find(z) != events.end()) status |= 2;
          
          z = a[i] + y;
          if (z <= m && events.find(z) != events.end()) status |= 2;
     }
     if (status == 3)
     {
          printf("0\n");
          return 0;
     }
     else
     if (status == 1) 
     {
          printf("1\n%d\n", y);
          return 0;
     }
     else
     if (status == 2)
     {
          printf("1\n%d\n", x);
          return 0;
     }
     else
     {
          events.clear();
          for (int i = 1; i <= n; i++)
          {      
               int z = a[i] - x;
               if (z > 0) events.insert(z);
               
               z = a[i] + x;
               if (z <= m) events.insert(z);
          }
          bool ok = true;
          for (int i = 1; i <= n && ok; i++)
          {      
               int z = a[i] - y;
               if (z > 0 && events.find(z) != events.end()) 
               {
                    printf("1\n%d\n", z);
                    ok = false;
                    break;
               }
               z = a[i] + y;
               if (z <= m && events.find(z) != events.end()) 
               {
                    printf("1\n%d\n", z);
                    ok = false;
                    break;
               }
          }
          if (ok) printf("2\n%d %d\n", x, y);
     }
}