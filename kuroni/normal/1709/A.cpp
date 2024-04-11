#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        vector<int> a(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        int sz = 0, u = 0;
        do {
            sz++;
            u = a[u];
        } while (u != 0);
        cout << (sz == 4 ? "YES\n" : "NO\n");
    }
}