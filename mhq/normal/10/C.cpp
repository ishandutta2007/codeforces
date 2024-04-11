#include <bits/stdc++.h>
using namespace std;
long long num[11];
long long d[11];
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int t = n % 9;
    int r = n / 9;
    //cout << r << endl;
    for ( int i = 0; i < 9; i++) {
        if ( i <= t && i > 0) {
           d[i]++;
        }
        d[i] += r;
    }
    long long ans = 0;
    for ( int i = 0; i < 9; i++) {
        for ( int j = 0; j < 9; j++) {
            ans += d[i] * d[j] * d[(i * j) % 9];
        }
    }
    long long p = 0;
    for ( int i = 1; i <= n; i++) {
        p += (n / i);
    }
    //cout << ans << endl;
    //cout << p << endl;
    cout << ans - p;
    return 0;
}