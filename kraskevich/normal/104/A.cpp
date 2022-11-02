#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    n -= 10;
    
    if(n == 1 || n == 11)
         cout << 4;
    if(n <= 0 || n > 11)
         cout << 0;
    if(n >= 2 && n < 10)
         cout << 4;
    if(n == 10)
         cout << 15;
    
    return 0;
}