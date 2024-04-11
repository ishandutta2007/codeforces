
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// x + 2y = a
// 2x + y = b
// x, y >= 0.

// 2(a - 2y) + y = b
// -3y = b - 2a
// y = (2a - b) / 3
// x = a - 2y

int t;
ll a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll y = (2 * a - b) / 3;
        ll x = a - 2 * y;
        if(y < 0 || x < 0 || (2 * a - b) % 3 != 0) {
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
        }
    }
}