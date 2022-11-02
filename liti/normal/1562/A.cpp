#include <bits/stdc++.h>
using namespace std; 

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) { 
        int l, r;
        cin >> l >> r; 
        
        int ans = (r % l);
        
        //2x - 1 = r => x = (r+1) / 2
        int x = (r+1) / 2;
        if (l <= x) {
            ans = max(ans, x-1);
        }
        
        cout << ans << '\n';
    }
}