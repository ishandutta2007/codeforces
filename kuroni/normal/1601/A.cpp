#include <bits/stdc++.h>
using namespace std;

const int LG = 31;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> cnt(LG);
        for (int i = 0; i < n; i++) {
            int u; cin >> u;
            for (int j = 0; j < 31; j++) {
                if (u >> j & 1) {
                    cnt[j]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            bool ok = true;
            for (int j = 0; j < LG; j++) {
                if (cnt[j] % i != 0) {
                    ok = false; break;
                }
            }
            if (ok) {
                cout << i << " ";
            }
        }
        cout << '\n';
    }
}