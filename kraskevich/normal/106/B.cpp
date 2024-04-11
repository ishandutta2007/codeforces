#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int n;
   
   cin >> n;
   
   bool old[n];
   for(int i = 0; i < n; ++i)
           old[i] = false;
   
   int a[n], b[n], c[n], cost[n], res = 1000 * 1000, resi;
   
   for(int i = 0; i < n; ++i)
           cin >> a[i] >> b[i] >> c[i] >> cost[i];
   
   for(int i = 0; i < n; ++i)
           for(int j = 0; j < n; ++j)
                   if(a[i] < a[j] && b[i] < b[j] && c[i] < c[j])
                           old[i] = true;
   
   for(int i = 0; i < n; ++i)
           if(!old[i]) 
                       if(cost[i] < res) {
                                  res = cost[i];
                                  resi = i;
                       }

   cout << resi + 1;
   
   cin >> n;
   return 0; 
}