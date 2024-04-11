
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll x, y, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x >> y >> a >> b;
        b = min(2 * a, b);
        cout << b * min(x, y) + a * (max(x, y) - min(x, y)) << '\n';
    }
}