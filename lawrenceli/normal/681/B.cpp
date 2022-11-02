#include <bits/stdc++.h>

using namespace std;

int a = 1234567, b = 123456, c = 1234;

int main() {
    int n; cin >> n;

    for (int i = 0; i <= n; i += a)
        for (int j = 0; j <= n - i; j += b)
            if ((n - i - j) % c == 0) {
                cout << "YES\n";
                return 0;
            }
    cout << "NO\n";
}