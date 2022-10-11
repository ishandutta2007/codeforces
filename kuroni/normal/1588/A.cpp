#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &v : a) {
            cin >> v;
        }
        for (int &v : b) {
            cin >> v;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool chk = true;
        for (int i = 0; i < n; i++) {
            chk &= (b[i] >= a[i] && b[i] <= a[i] + 1);
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}