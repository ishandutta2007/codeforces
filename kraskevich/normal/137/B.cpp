#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
  int n;
  
  cin >> n;
  
  int a[n], res = 0;
  
  for(int i = 0; i < n; ++i)
          cin >> a[i];
  
  bool u[n + 1];
  
  for(int i = 1; i <= n; ++i)
          u[i] = false;
   
  for(int i = 0; i < n; ++i)
          if(a[i] >= 1 && a[i] <= n) 
                  u[a[i]] = true; 
  for(int i = 1; i <= n; ++i)
          if(!u[i])
                   ++res;
                   
   cout << res;
   
   cin >> n;      
  
  return 0;
}