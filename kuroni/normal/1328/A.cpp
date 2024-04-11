#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << ((a - 1) / b + 1) * b - a << '\n';
    }
}