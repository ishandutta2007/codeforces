#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int u; cin >> u;
            if (i <= k && u > k) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}