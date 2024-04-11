#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<long long> a(n), pf(n), sf(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i > 0; i--) {
        pf[i] = max(0LL, a[i - 1] - a[i]);
        sf[i - 1] = sf[i] + max(0LL, a[i] - a[i - 1]);
    }
    for (int i = 1; i < n; i++) {
        pf[i] += pf[i - 1];
    }
    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        cout << (l < r ? pf[r] - pf[l] : sf[r] - sf[l]) << '\n';
    }
}