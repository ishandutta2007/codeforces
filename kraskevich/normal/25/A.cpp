#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
   int n;
   
   cin >> n;
   
   int a[n];
   
   for(int i = 0; i < n; ++i)
           cin >> a[i];
   
   int c[2];
   c[0] = c[1] = 0;
   
   for(int i = 0; i < n; ++i)
           c[a[i] % 2]++;
           
   int t;
   if(c[0] > c[1])
           t = 0;
   else
       t = 1;
   for(int i = 0; i < n; ++i)
           if(a[i] % 2 != t) {
                   cout << i + 1;
                   return 0;
           }
    
}