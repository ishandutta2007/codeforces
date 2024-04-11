#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int no_nils(int a) {
    int res = 0, t = 1;
    while(a) {
               int cur = a % 10;
               if(cur) {
                       res += cur * t;
                       t *= 10;
               }
               a /= 10;
    }
    return res;
}

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int c = a + b;
    c = no_nils(c);
    a = no_nils(a);
    b = no_nils(b);
    
    cout << (a + b == c ? "YES" : "NO");
    
    cin >> a;
    
    return 0;
}