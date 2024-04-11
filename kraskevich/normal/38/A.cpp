#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int a[n], sum = 0;
    
    for(int i = 1; i < n; ++i)
            cin >> a[i];
            
    int cur, want, res = 0;
    
    cin >> cur >> want;
    
    for(int i = cur; i < want; ++i)
            res += a[i];
    
    cout << res << endl;
    
    cin >> n;
    return 0;
}