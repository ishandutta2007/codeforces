#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if (a + b == c || a + c == b || b + c == a || a == b && c % 2 == 0 || b == c && a % 2 == 0 || c == a && b % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}