#include <iostream>
using namespace std;

int main() {
    long long n;
    
    cin >> n;
    
    long long mn = 1e15, mx = 0;
    for(long long i = 1; i * i * i <= n; ++i)
            for(long long j = 1; j * j * i <= n; ++j) 
                    if(n % (i * j) == 0) {
                         long long k = n / (i * j);
                         mn = min(mn, (i + 2) * (j + 2) * (k + 1) - n);
                         mx = max(mx, (i + 2) * (j + 2) * (k + 1) - n);
                         mn = min(mn, (i + 1) * (j + 2) * (k + 2) - n);
                         mx = max(mx, (i + 1) * (j + 2) * (k + 2) - n);
                         mn = min(mn, (i + 2) * (j + 1) * (k + 2) - n);
                         mx = max(mx, (i + 2) * (j + 1) * (k + 2) - n);
                    }
    
    cout << mn << " " << mx;
    
    cin >> n;
    
    return 0;
}