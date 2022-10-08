
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll x, y;
        for(x = 2; x * x <= n; x++) {
            if(n % x != 0) continue;
            for(y = 2; y * y < x; y++) {
                if(x % y != 0) continue;
                cout << "YES" << endl << y << " " << (x / y) << " " << (n / x) << endl;
                goto endloop;
            }
            for(y = 2; y * y < (n / x); y++) {
                if((n / x) % y != 0) continue;
                if(y != x && (n / x) / y != x) {
                    cout << "YES" << endl << x << " " << y << " " << (n / x) / y << endl;
                    goto endloop;
                }
            }
        }
        cout << "NO" << endl;
        endloop:;
    }
}