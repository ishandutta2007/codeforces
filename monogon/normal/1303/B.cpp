
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n, g, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> g >> b;
        ll m = (n + 1) / 2;
        if(m % g == 0) {
            cout << max(n, (m / g - 1) * (g + b) + g) << endl;
        }else {
            cout << max(n, (m % g) + (m / g) * (g + b)) << endl;
        }
    }
}