#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        int n, k;
        cin >> n >> k;
        if (k == n - 1) {
            if (n == 4) cout << "-1\n";
            else {
                cout << 0 << ' ' << 2 << '\n';
                cout << 1 << ' ' << n - 3 << '\n';
                cout << n - 1 << ' ' << n - 2 << '\n';
                for (int i = 3 ; i < n / 2 ; ++ i) {
                    cout << i << ' ' << ((n - 1) ^ i) << '\n';
                }
            }
            continue;
        }
        for (int i = 1 ; i < n / 2 ; ++ i) {
            if (i != k && ((n - 1) ^ i) != k) {
                cout << i << " " << ((n - 1) ^ i) << '\n';
            }
        }
        if (k == 0) {
            cout << 0 << ' ' << n - 1 << '\n';
        } else {
            cout << 0 << ' ' << ((n - 1) ^ k) << '\n';
            cout << n - 1 << ' ' << k << '\n';
        }
        /**
            0 n - 1
            1 n - 2
            2 n - 3
        */
    }
}