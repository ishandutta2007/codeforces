#include <iostream>
using namespace std;

int main() {
   int n;
   
   cin >> n;
   
   for(int i = 0; i < n / 4; ++i)
           cout << "abcd";
   for(int i = 0; i < n % 4; ++i)
           cout << char('a'+ i);
   
   cin >> n;
   
   return 0; 
}