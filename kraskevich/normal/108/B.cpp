#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
   int n;
   
   cin >> n;
   
   int a[n];
   
   for(int i = 0; i < n; ++i)
           cin >> a[i];
           
   sort(a, a + n);
   
   for(int i = 1; i < n; ++i) {
           if(a[i] < 2 * a[i - 1] && a[i] != a[i - 1]) {
                   cout << "YES";
                   cin >> n;
                   return 0;
           }
   }
   
   cout << "NO";
   
   cin >> n;
   
   return 0; 
}