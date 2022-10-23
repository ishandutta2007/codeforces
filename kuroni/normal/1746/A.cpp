#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        bool ok = false;
        while (n--) {
            int u; cin >> u;
            ok |= u;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}