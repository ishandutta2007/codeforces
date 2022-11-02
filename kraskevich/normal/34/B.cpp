#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    sort(a, a + n);
    
    int res = 0, i = 0;

    while(a[i] < 0 && i < min(n, m)) {
               res -= a[i];
               ++i;
    }
               
    cout << res;
    
    cin >> n;
    return 0;
}