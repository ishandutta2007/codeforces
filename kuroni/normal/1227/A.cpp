#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int ll = INF, rr = 0; int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int l, r; cin >> l >> r;
            ll = min(ll, r); rr = max(rr, l);
        }
        cout << max(0, rr - ll) << '\n';
    }
}