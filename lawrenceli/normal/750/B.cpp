#include <bits/stdc++.h>

using namespace std;

const int mod = 20000;

int cur;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t; string d;
        cin >> t >> d;
        if (d == "West" || d == "East") {
            if (cur == 0 || cur == mod) {
                cout << "NO\n";
                return 0;
            }
        } else {
            if (d == "North") t = -t;
            cur += t;
            if (cur < 0 || cur > mod) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << (cur == 0 ? "YES\n" : "NO\n");
}