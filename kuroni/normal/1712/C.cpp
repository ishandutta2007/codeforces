#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), lst(n + 1, -1);
        vector<bool> chk(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            lst[a[i]] = i;    
        }
        int suf = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] <= a[i + 1]) {
                suf = i;
            } else {
                break;
            }
        }
        int ans = 0;
        for (int i = 0, xd = -1; i < suf || i <= xd; i++) {
            if (!chk[a[i]]) {
                ans++;
                chk[a[i]] = true;
                xd = max(xd, lst[a[i]]);
            }
        }
        cout << ans << '\n';
    }
}