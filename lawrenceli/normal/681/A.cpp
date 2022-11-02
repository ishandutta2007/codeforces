#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string trash; int a, b;
        cin >> trash >> a >> b;
        if (a >= 2400 && b > a) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}