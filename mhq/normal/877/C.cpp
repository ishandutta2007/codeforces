#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n % 2 == 0) {
        cout << 3 * (n / 2) << '\n';
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i << " ";
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i - 1 << " ";
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i << " ";
        }
    }
    else {
        cout << 3 * (n / 2) + 1 << '\n';
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i << " ";
        }
        for (int i = 1; i <= n / 2 + 1; i++) {
            cout << 2 * i - 1 << " ";
        }
        for (int i = 1; i <= n / 2; i++) {
            cout << 2 * i << " ";
        }
    }
    return 0;
}