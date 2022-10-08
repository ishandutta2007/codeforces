
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
ll x, d, h;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll maxD = 0;
        ll maxDiff = -1;
        for(int i = 0; i < n; i++) {
            cin >> d >> h;
            maxD = max(maxD, d);
            maxDiff = max(maxDiff, d - h);
        }
        if(maxDiff <= 0 && maxD < x) {
            cout << -1 << endl;
        }else if(maxD >= x) {
            cout << 1 << endl;
        }else {
            cout << (1 + (x - maxD + maxDiff - 1) / maxDiff) << endl;
        }
    }
}