#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int o = 0, z = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            z += (a[i] == 0);
        }
        if (is_sorted(a.begin(), a.end())) {
            cout << "0\n";
        } else {
            int ans = 2 * n;
            for (int i = 0; i < n; i++) {
                if (o >= z) {
                    ans = min(ans, o);
                }
                o += (a[i] == 1); z -= (a[i] == 0);
                // cout << i << " " << o << " " << z << '\n';
            }
            cout << ans << '\n';
        }
    }
}