#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int n;
   
   cin >> n;
   
   int a[n];
   
   for(int i = 0; i < n; ++i)
           cin >> a[i];
   
   sort(a, a + n);
   int k = 1, maxH = 1, cur = 1;
   
   for(int i = 1; i < n; ++i) {
           if(a[i] == a[i - 1]) 
                   cur++;
           else {
                k++;
                cur = 1;
           }
           maxH = max(maxH, cur);
   }
   
   cout << maxH << " " << k;
   
   cin >> n;
   return 0;                
}