#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, d = 1000, ans1, ans2;
    cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    for(int i = 0; i < n; ++i) {
            int cur = fabs(a[i] - a[(i + 1) % n]);
            if(cur < d) {
                   d = cur;
                   ans1 = i;
                   ans2 = (i + 1) % n;
            }
    }
    
    cout << ans1 + 1 << " " << ans2 + 1;
      
    return 0;
}