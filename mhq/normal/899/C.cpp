#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    if (n % 4 == 0) {
        cout << 0 << '\n';
        cout << 2 * (n / 4) << " ";
        for (int i = 0; i < n / 4; i++) cout << 4 * i + 1 << " " << 4 * i + 4 << " ";
    }
    if (n % 4 == 1) {
        cout << 1 << '\n';
        cout << 2 * (n / 4) << " ";
        for (int i = 2; i <= n; i += 4) cout << i << " ";
        for (int i = 5; i <= n; i += 4) cout << i << " ";
    }
    if (n % 4 == 2) {
        cout << 1 << '\n';
        cout << 2 * (n / 4) + 1 << " ";
        cout << 1 << " ";
        for (int i = 3; i <= n; i += 4) cout << i << " ";
        for (int i = 6; i <= n; i += 4) cout << i << " ";
    }
    if (n % 4 == 3) {
        cout << 0 << '\n';
        cout << 2 * (n / 4) + 2 << " ";
        cout << 1 << " " << 2 << " ";
        for (int i = 4; i <= n; i += 4) cout << i << " ";
        for (int i = 7; i <= n; i += 4) cout << i << " ";
    }
    return 0;
}