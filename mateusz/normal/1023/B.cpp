#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long n, k;
    
    cin >> n >> k;
    n = min(n, k - 1);
    
    long long mid = k / 2;
    long long ans = max(0LL, n - mid);
    
    cout << ans << endl;
    
    return 0;
}