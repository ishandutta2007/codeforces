#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2 == 1) {
            cout << 1 << " ";
        }
        for (int i = n % 2 + 1; i <= n; i += 2) {
            cout << i + 1 << " " << i << " ";
        }
        cout << '\n';
    }
}