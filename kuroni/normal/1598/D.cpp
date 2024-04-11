#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        vector<int> ct(n), cd(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            a[i]--; b[i]--;
            ct[a[i]]++; cd[b[i]]++;
        }
        long long x1 = 1LL * n * (n - 1) * (n - 2) / 6;
        long long x2 = 1LL * n * (n - 1) * (n - 2) / 6;
        long long x12 = 1LL * n * (n - 1) * (n - 2) / 6;
        for (int i = 0; i < n; i++) {
            int c = ct[i];
            x12 -= 1LL * c * (c - 1) / 2 * (n - c);
            x12 -= 1LL * c * (c - 1) * (c - 2) / 6;
            x1 -= 1LL * c * (c - 1) / 2 * (n - c);
            x1 -= 1LL * c * (c - 1) * (c - 2) / 6;
            c = cd[i];
            x12 -= 1LL * c * (c - 1) / 2 * (n - c);
            x12 -= 1LL * c * (c - 1) * (c - 2) / 6;
            x2 -= 1LL * c * (c - 1) / 2 * (n - c);
            x2 -= 1LL * c * (c - 1) * (c - 2) / 6;
        }
        for (int i = 0; i < n; i++) {
            x12 += 1LL * (ct[a[i]] - 1) * (cd[b[i]] - 1);
        }
        cout << x1 + x2 - x12 << '\n';
    }
}