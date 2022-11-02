#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

int n, a[105], t;

int main() {
    ios :: sync_with_stdio(false);
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> t;
    
    sort(a, a + n);
    
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (a[j] - a[i] <= t)
                ans = max(ans, j - i + 1);
        }
    }
    
    cout << ans << '\n';
    return 0;
}