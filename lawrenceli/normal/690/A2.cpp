#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    if (n % 2 == 0) {
        for (int i = 0; 1; i++) {
            int x = n - 2 * i;
            if (x <= 0 || (x == (1<<__builtin_ctz(x)))) {
                cout << i << '\n';
                return 0;
            }
        }
    } else cout << (n - 1) / 2 << '\n';
}