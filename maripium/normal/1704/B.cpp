#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, X; cin >> N >> X;
        int lo = -1e9, hi = 2e9;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            int nlo = a - X;
            int nhi = a + X;
            if (nlo > hi || nhi < lo) {
                ans ++;
                lo = nlo;
                hi = nhi;
            } else {
                lo = max(lo, nlo);
                hi = min(hi, nhi);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}