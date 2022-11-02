#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    long long a[n], s[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    for(int i = 0; i < n; ++i) {
            s[i] = a[i];
            if(i)
                 s[i] += s[i - 1];
    }
    
    int res = 0;
    
    for(int k = 1; k <= n - 1; ++k) {
            long long sumL = s[k - 1], sumR = s[n - 1] - s[k - 1];
            if(sumL == sumR)
                    ++res;
    }
    
    cout << res;
    
    cin >> n; 
    
    return 0;
}