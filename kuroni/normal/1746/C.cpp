#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<pair<int, int>> xd;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            xd.push_back({a[i] - (i == 0 ? 0 : a[i - 1]), i});
        }
        sort(xd.begin(), xd.end(), greater<pair<int, int>>());
        for (int i = 0; i < n; i++) {
            auto [val, ind] = xd[i];
            // assert(val <= i + 1);
            cout << ind + 1 << ' ';
        }
        cout << '\n';
    }
}