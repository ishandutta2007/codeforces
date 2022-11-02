#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, a, b;
    
    cin >> n >> a >> b;
    
    int l = max(n - b, a + 1);
    
    cout << n - l + 1;
    
    cin >> n;
    
    return 0; 
}