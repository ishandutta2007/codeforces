#include <iostream>
#include <string>
using namespace std;

char lower_case(char c) {
     if(c >= 'a')
          return c;
     else
         return c - 'A' + 'a';
}

int main() {
    string a, b;
    
    cin >> a >> b;
    
    for(int i = 0; i < a.length(); ++i)
            a[i] = lower_case(a[i]);
            
    for(int i = 0; i < b.length(); ++i)
            b[i] = lower_case(b[i]);
            
    if(a > b)
         cout << 1;
    if(a == b)
         cout << 0;
    if(a < b)
         cout << -1;
         
    return 0;
}