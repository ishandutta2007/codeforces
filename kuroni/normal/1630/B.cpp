#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b = a; sort(b.begin(), b.end());
        pair<int, int> ans = {numeric_limits<int>::max(), 0};
        for (int i = 0; i < n; i++) {
            int nxt = i + (n + k + 1) / 2 - 1;
            if (nxt < n) {
                ans = min(ans, {b[nxt] - b[i], b[i]});
            }
        }
        auto [r, l] = ans; r += l;
        cout << l << " " << r << '\n';
        cout << 1 << ' ';
        for (int i = 0, cnt = 0, rng = 1; i < n; i++) {
            if (rng == k) {
                cout << n << '\n';
                break;
            }
            cnt += (a[i] >= l && a[i] <= r ? 1 : -1);
            if (cnt == rng) {
                cout << i + 1 << '\n' << i + 2 << " ";
                rng++;
            }
            if (rng == k) {
                cout << n << '\n';
                break;
            }
        }
    }
}