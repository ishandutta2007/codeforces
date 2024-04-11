#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, x;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> x;
        cout << 3 * n << '\n';
        for (int i = 0; i < n; i += 2) {
            for (int j = 0; j < 3; ++j) {
                cout << "2 " << i + 1 << ' ' << i + 2 << '\n';
                cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
            }
        }
    }
    return 0;
}