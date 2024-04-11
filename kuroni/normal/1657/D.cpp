#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, C; cin >> n >> C;
    vector<long long> dm(C + 1);
    for (int i = 1; i <= n; i++) {
        int c, d, h; cin >> c >> d >> h;
        dm[c] = max(dm[c], 1LL * d * h);
    }
    for (int i = C; i >= 1; i--) {
        for (int j = i; j <= C; j += i) {
            dm[j] = max(dm[j], j / i * dm[i]);
        }
    }
    for (int i = 1; i <= C; i++) {
        dm[i] = max(dm[i], dm[i - 1]);
    }
    int q; cin >> q;
    while (q--) {
        long long d, h; cin >> d >> h;
        int x = upper_bound(dm.begin(), dm.end(), d * h) - dm.begin();
        if (x > C) {
            cout << "-1 ";
        } else {
            cout << x << ' ';
        }
    }
}