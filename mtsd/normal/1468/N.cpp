#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        vector<int> c(3);
        for (int i = 0; i < 3; ++i) {
            cin >> c[i];
        }
        vector<int> a(5);
        for (int i = 0; i < 5; ++i) {
            cin >> a[i];
        }
        c[0] -= a[0];
        c[1] -= a[1];
        c[2] -= a[2];
        if (c[0] < 0 || c[1] < 0 || c[2] < 0) {
            cout << "NO\n";
            continue;
        }
        int x = a[3];
        int y = a[4];
        x -= min(c[0], x);
        y -= min(c[1], y);
        if (x + y <= c[2]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}