#include <bits/stdc++.h>
using namespace std;

int t, n;
long long u;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        long long su = 0, xo = 0;
        for (int i = 1; i <= n; i++) {
            cin >> u;
            su += u;
            xo ^= u;
        }
        cout << "2\n" << xo << " " << su + xo << '\n';
    }
}