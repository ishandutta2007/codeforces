#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    k = 240 - k;
    for (int i = 1; i <= n; i++) {
        if (5 * i > k) {
            cout << i - 1;
            return 0;
        }
        k -= 5 * i;
    }
    cout << n;
}