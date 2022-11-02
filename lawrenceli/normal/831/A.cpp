#include <bits/stdc++.h>
using namespace std;

int n, a[105];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int st = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] < a[i + 1]) {
            if (st > 0) {
                cout << "NO";
                return 0;
            }
        } else if (a[i] == a[i + 1]) {
            if (st > 1) {
                cout << "NO";
                return 0;
            }
            st = 1;
        } else {
            st = 2;
        }
    }
    cout << "YES";
}