
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll a, b, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll x = abs(b - a);
        cout << ((x / 5) + (x % 5) / 2 + ((x % 5) % 2)) << endl;
    }
}