#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    
    cin >> a >> b;
    
    if(a.length() != b.length()) {
                  cout << "NO";
                  return 0;
    }
    int i = 0, j = a.length() - 1;
    for(; j >= 0; --j, ++i)
         if(a[i] != b[j]) {
                 cout << "NO";
                 return 0;
         }
    
    cout << "YES";
    
    return 0;              
}