#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    bool f[10 * n];
    
    for(int i = 0; i < 10 * n; ++i)
            f[i] = false;
    
    int cur = 1, step = 2;
    f[1] = true;
    while(cur <= n) {
              cur = cur + step;
              f[cur] = true;
              step++;
    }
    
    cout << (f[n] ? "YES" : "NO");
    
    cin >> n;
    return 0; 
}