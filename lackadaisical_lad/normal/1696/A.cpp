#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] |= z;
    }
    cout << *max_element(a.begin(), a.end()) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
    cin >> T;
    while (T--) {
        solve();
    }
}