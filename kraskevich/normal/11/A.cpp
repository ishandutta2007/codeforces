#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
  int n, d;
  
  cin >> n >> d;
  
  long long a[n];
  
  for(int i = 0; i < n; ++i)
          cin >> a[i];
   
   long long prev = a[0], steps = 0;
   
   for(int i = 1; i < n; ++i)  
           if(a[i] <= prev) {
                   steps += (-a[i] + prev) / d + 1;
                   prev = ((-a[i] + prev) / d + 1) * d + a[i];
           }
           else
               prev = a[i];
   
   cout << steps;
   
   cin >> n;
   
   return 0;       
}