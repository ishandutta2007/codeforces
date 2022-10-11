#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n == 1) {
            cout << (a[0] == 1 ? "YES\n" : "NO\n");
        } else {
            cout << (a[n - 1] <= a[n - 2] + 1 ? "YES\n" : "NO\n");
        }
    }
}