#include <iostream>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << '7';
            n /= 2;
            n--;
            for (int i = 0; i < n; i++) {
                cout << '1';
            }
            cout << '\n';
        } else {
            n /= 2;
            for (int i = 0; i < n; i++) {
                cout << '1';
            }
            cout << '\n';
        }
    }
}