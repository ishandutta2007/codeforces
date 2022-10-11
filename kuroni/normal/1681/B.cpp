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
        int m, cur = 0; cin >> m;
        while (m--) {
            int u; cin >> u;
            (cur += u) %= n;
        }
        cout << a[cur] << '\n';
    }
}