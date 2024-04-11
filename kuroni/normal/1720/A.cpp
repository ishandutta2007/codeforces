#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        long long a, b, c, d; cin >> a >> b >> c >> d;
        if (a * d == b * c) {
            cout << 0 << '\n';
        } else {
            long long x = a * d, y = b * c;
            if (y != 0 && x % y == 0 || x != 0 && y % x == 0) {
                cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
    }
}