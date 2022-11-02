#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int a[n], sum = 0;
    
    for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
    }
    
    int res = 0;
    
    for(int i = 0; i < n; ++i)
            if((sum - a[i]) % 2 == 0)
                    ++res;
                    
    cout << res;
    
    return 0;
}