#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mx = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mx = max(mx, x), sum += x;
        }

        if (mx * 2 > sum || sum % 2)
            cout << "T\n";
        else
            cout << "HL\n";
    }
}