#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ) {
        if (i == n || i + 1 == n) {
            return cout << 1, 0;
        }
        i = 2 * i + 1 + (i & 1);
    }
    cout << 0;
}