#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d, xl, x, xr, yl, y, yr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cin >> x >> y >> xl >> yl >> xr >> yr;
        x += b - a; y += d - c;
        if (xl <= x && x <= xr && yl <= y && y <= yr
            && ((a == 0 && b == 0) || xl != xr) && ((c == 0 && d == 0) || yl != yr)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}