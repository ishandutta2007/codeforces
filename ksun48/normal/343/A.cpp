#include <iostream>
using namespace std;

int main() {
    
    long long a, b;
    cin >> a >> b;
    long long k = 0;
    while(a > 0 && b > 0){
     if(b>a){
        long long c = b;
        b = a;
        a = c;
     }
     k += a/b;
     //cout << a/b << endl;
     a %= b;
     //cout << a << " " << b << endl;
    }
    cout << k << endl;
    return 0;
}