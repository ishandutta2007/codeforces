#include <iostream>
using namespace std;

int main() {
    int n, m, a, b;
    
    cin >> n >> m >> a >> b;
    
    --a, --b;
    
    int xl = a % m, yl = a / m, xr = b % m, yr = b / m;
    
    if(yl == yr) 
          cout << 1;
    else {
        if(xl == 0 && xr == m - 1 || xl == 0 && b == n - 1)
              cout << 1;
        else {
            if(xl == 0 || xr == m - 1 || b == n - 1 || xr == xl - 1 || yl == yr - 1)
                  cout << 2;
            else
                cout << 3;
        }       
   }
   return 0; 
}