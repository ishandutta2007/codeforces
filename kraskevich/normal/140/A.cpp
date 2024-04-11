#include <iostream>
#include <cmath>
using namespace std;

const double pi = acos(-1), eps = 1e-7;

int main() {
    int n, R, r;
    bool ok;
    
    cin >> n >> R >> r;
    
    if(n == 1)
         ok = (r <= R);
    if(n == 2)
         ok = (r * 2 <= R);
    if(n > 2) 
         ok = ( sin(pi / n) * (R - r) + eps >= r);
    
    cout << (ok ? "YES" : "NO");
    
    return 0;
}