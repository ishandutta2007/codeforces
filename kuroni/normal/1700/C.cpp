#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            a[i] -= a[i - 1];
        }
        // a[1]--, a[i]++
        // a[i]--
        // a[1]++
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += abs(a[i]);
            a[0] += min(0LL, a[i]);
        }
        ans += abs(a[0]);
        cout << ans << '\n';
    }
}