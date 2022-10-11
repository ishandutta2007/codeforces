#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n, a[N], col[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool chk = false;
    for (int i = 0; i < n; i++) {
        if (a[i] != a[(i + 1) % n]) {
            chk = true;
        }
    }
    if (!chk) {
        cout << "1\n";
        for (int i = 0; i < n; i++) {
            cout << "1 ";
        }
    } else {
        col[0] = n & 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                col[i] = col[i - 1] ^ 1;
            } else {
                col[i] = i & 1;
            }
        }
        if (a[0] != a[n - 1] && col[0] == col[n - 1]) {
            col[n - 1] = 2;
            cout << "3\n";
        } else {
            cout << "2\n";
        }
        for (int i = 0; i < n; i++) {
            cout << col[i] + 1 << ' ';
        }
    }
    cout << '\n';
}
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}