#include <iostream>
using namespace std;

int main() {
   int n;
   
   cin >> n;
   
   long long a[n];
   
   for(int i = 0; i < n; ++i)
           cin >> a[i];
   
   long long sum = 0;
   
   for(int i = 0; i < n; ++i)
           sum += (a[i] == 1 ? 1 : a[i] + i * (a[i] - 1)); 
   
   cout << sum;
   
   cin >> n;
   return 0;
}