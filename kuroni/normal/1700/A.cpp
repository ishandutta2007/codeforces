#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int m, n; cin >> m >> n;
        cout << 1LL * n * (n - 1) / 2 + 1LL * n * m * (m + 1) / 2 << '\n';
    }
}