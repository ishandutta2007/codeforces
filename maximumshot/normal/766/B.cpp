#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector< int > a(n);
    
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int ok = 0;
    
    for(int i = 2;i < n;i++) {
        if(a[i] < a[i - 1] + a[i - 2]) {
            ok = 1;
            break;
        }
    }
    
    cout << (ok ? "YES" : "NO") << "\n";
    
    return 0;
}