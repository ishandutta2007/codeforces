#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b;
    
    cin >> a >> b;
    
    cout << (6 - max(a, b) + 1) / gcd(6,6 -  max(a, b) + 1) << '/' << 6 / gcd(6, 6 - max(a, b) + 1);
    
    cin >> a;
    
    return 0;
}