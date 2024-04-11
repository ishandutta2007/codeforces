#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << x + y + max(0, abs(x - y) - 1) << '\n';
    }
}