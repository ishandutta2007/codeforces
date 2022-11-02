#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int a, b = 1;
    cin >> a; 
    a = max(a, -a);
    
    for(; a > 0 || max(a, -a) % 2 != 0; b++)
          a -= b;
    
    cout << --b;
    
    return 0;
}