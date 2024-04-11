#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int h[n];
    
    for(int i = 0; i < n; ++i)
            cin >> h[i];
            
    int maxN = 0;
    
    for(int i = 0; i < n; ++i) {
            int k = i, j = i;
            while(k > 0 && h[k] >= h[k - 1])
                    --k;
            while(j < n - 1 && h[j] >= h[j + 1])
                    ++j;
            maxN = max(maxN, j - k + 1);
    }
    
    cout << maxN;
    
    return 0;  
}