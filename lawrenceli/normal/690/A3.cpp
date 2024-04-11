#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n, r; cin >> n >> r;
        int x = 0;
        for (int j = 0; j < n - 1; j++) {
            int a; cin >> a; x = (x + a) % n;
        }
        x = (r + n - x) % n;
        if (!x) x = n;
        cout << x << '\n';
    }
}