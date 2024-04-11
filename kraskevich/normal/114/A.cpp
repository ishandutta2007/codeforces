#include <iostream>
using namespace std;

int main() {
    int k, l;
    
    cin >> k >> l;
    
    int p = 0;
    
    while(l > 1 && l % k == 0) {
            ++p;
            l /= k;
    }
            
    if(l != 1)
         cout << "NO";
    else
        cout << "YES" << endl << p - 1;
        
    cin >> k;
        
    return 0;      
}