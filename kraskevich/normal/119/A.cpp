#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    for(int i = 0;;++i) { 
            //cout << i << " " << a << " " << b << " " << n << endl;       
            if(i % 2 == 0) {
                 int g = gcd(a, n);
                 if(g > n) {
                      cout << 1;
                      cin >> n;
                      return 0;
                 }
                 //a += g;
                 n -= g;
            }
            else {
                 int g = gcd(b, n);
                 if(g > n) {
                      cout << 0;
                      cin >> n;
                      return 0;
                 }
                 //b += g;
                 n -= g;
            }
    }
}