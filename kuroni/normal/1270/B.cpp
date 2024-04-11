#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5;

int n, t, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool chk = false;
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i + 1]) >= 2) {
                cout << "YES\n" << i << " " << i + 1 << '\n';
                chk = true;
                break;
            }
        }
        if (!chk) {
            cout << "NO\n";
        }
    }
}