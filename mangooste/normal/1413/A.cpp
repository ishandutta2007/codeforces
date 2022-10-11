#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        assert(n % 2 == 0);
        for (int i = 0; i < n / 2; i++) {
            cout << -a[n - i - 1] << ' ';
        }
        for (int i = n / 2; i < n; i++) {
            cout << a[n - 1 - i] << ' ';
        }
        cout << '\n';
    }
}