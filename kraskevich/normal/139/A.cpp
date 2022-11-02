#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int a[7];
    
    for(int i = 0; i < 7; ++i)
            cin >> a[i];
    
    int i;
    
    for(i = 0; n > 0;  i = (i + 1) % 7) 
          n -= a[i];
    
    i = (i + 7 - 1) % 7;      
    cout << i + 1 << endl;
    
    cin >> n;
    
    return 0;
}