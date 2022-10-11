#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n, 1);
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (INF / 3 < a[i - 1]) {
                ok = false;
                break;
            } else {
                a[i] = 3 * a[i - 1];
            }
        }
        if (ok) {
            cout << "YES\n";
            for (int v : a) {
                cout << v << " ";
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}