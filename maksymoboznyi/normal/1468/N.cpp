#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int c[3];
        for (int& cc : c) cin >> cc;
        int a[5];
        for (int& aa : a) cin >> aa;
        bool isYes = true;
        for (int i = 0; i < 3; ++i) {
            if (c[i] >= a[i]) {
                c[i] -= a[i];
            } else {
                isYes = false;
            }
        }
        if (!isYes) {
            cout << "NO\n";
            continue;
        }
        if (c[0] > 0) {
            a[3] -= c[0];
            c[0] = 0;
        }
        if (c[1] > 0) {
            a[4] -= c[1];
            c[1] = 0;
        }
        if (a[3] > 0 && c[2] >= a[3]) {
            c[2] -= a[3];
            a[3] = 0;
        } else if (a[3] > 0 && c[2] < a[3]) {
            isYes = false;
        }
        if (a[4] > 0 && c[2] >= a[4]) {
            c[2] -= a[4];
            a[4] = 0;
        } else if (a[4] > 0 && c[2] < a[4]) {
            isYes = false;
        }
        if (!isYes) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }   
}