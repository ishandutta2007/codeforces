#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n - n / 4 - 1; i++) {
            cout << 9;
        }
        cout << (n % 4 == 0 ? 9 : 8);
        for (int i = 0; i < n / 4; i++) {
            cout << 8;
        }
        cout << '\n';
    }
}