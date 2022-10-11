#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, q;
long long cur, a[N][N];

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (1LL << (i + j)) * (i % 2);
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
    cout << flush;
    cin >> q;
    while (q--) {
        cin >> cur;
        int x = 0, y = 0;
        cout << "1 1" << endl;
        for (int i = 1; i < 2 * n - 1; i++) {
            if (x == n - 1) {
                y++;
            } else if (y == n - 1) {
                x++;
            } else if ((cur >> i & 1) ^ (x % 2)) {
                x++;
            } else {
                y++;
            }
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
}