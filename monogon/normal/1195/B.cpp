
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ll l = 0, r = n - 1;
    while(l <= r) {
        ll m = (l + r) / 2;
        ll val = -m + (n - m) * (n - m + 1) / 2;
        if(val > k) {
            l = m + 1;
        }else if(val < k) {
            r = m - 1;
        }else {
            cout << m << endl;
            return 0;
        }
    }
}