#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = -1, r = -2;
    for (int i = 0; i < n; i++)
        if (a[i] > 0) {
            if (l == -1) l = i;
            r = i;
        }
    bool ok = true;
    for (int i = l; i <= r; i++)
        ok &= a[i] > 0;

    int low = *min_element(a.begin(), a.end());
    int top = *max_element(a.begin(), a.end());
    if (top == 0) {
        cout << "0\n";
    } else if (low > 0 || ok) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
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