#include <bits/stdc++.h>
using namespace std;
bool b[1000];
int a[1000];
int main() {
    int n, x;
    cin >> n >> x;
    for ( int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = true;
    }
    int ans = 0;
    for ( int i = 0; i < x; i++) {
        if ( b[i] == false) {
            ans++;
        }
    }
    if ( b[x] == true) ans++;
    cout << ans;
    return 0;
}