#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (n == 4 && k == 3) {
            cout << "-1\n";
        } else if (k < n - 1) {
            for (int i = 0; i < n / 2; i++) {
                if (i == 0) {
                    cout << "0 " << n - 1 - k << '\n';
                } else if (i == k) {
                    cout << i << " " << n - 1 << '\n';
                } else if (i == n - k - 1) {
                    cout << k << " " << n - 1 << '\n';
                } else {
                    cout << i << " " << n - 1 - i << '\n';
                }
            }
        } else {
            k--; int fi = n / 2 + 1, se = n / 2 - 1;
            for (int i = 0; i < n / 2; i++) {
                if (i == 0) {
                    cout << "0 " << n - 1 - k << '\n';
                } else if (i == k) {
                    cout << i << " " << n - 1 << '\n';
                } else if (i == n - k - 1) {
                    cout << k << " " << n - 1 << '\n';
                } else if (i == se) {
                    cout << se << " " << fi << '\n';
                } else if (i == n - 1 - fi) {
                    cout << n - 1 - fi << " " << n - 1 - se << '\n';
                } else {
                    cout << i << " " << n - 1 - i << '\n';
                }
            }
        }
    }
}