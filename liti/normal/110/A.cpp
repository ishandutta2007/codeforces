#include <iostream>
using namespace std;

int main() { 
 long long n;
 cin >> n;
 int ret = 0;
 while(n) { 
  if(n % 10 == 4 || n % 10 == 7 ) 
   ret++;
  n /=10;
 }
 cout << (ret == 7 || ret == 4 ?"YES":"NO") <<endl;
}