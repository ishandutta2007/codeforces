#include <iostream>
using namespace std;

int main() {
    bool u[3002];
    
    for(int i = 0; i <= 3001; ++i)
            u[i] = false;
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; ++i) { 
            int a;
            cin >> a;
            u[a] = true;
    }
    
    for(int i = 1;; ++i) 
            if(!u[i]) {
                      cout << i;
                      return 0;
            }
}