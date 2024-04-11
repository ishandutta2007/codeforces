
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll ans = n;
        int k = 1e9;
        while(n > 0) {
            while(k > n) k /= 10;
            ans += (n / k) * k / 10;
            n += (n / k) * k / 10 - (n / k) * k;
        }
        cout << ans << endl;
    }
}