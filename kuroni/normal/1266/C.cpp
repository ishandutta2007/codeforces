#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    if (m == 1 && n == 1) {
        return cout << 0, 0;
    } else {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << (m <= n ? i : i + n) * (n < m ? j : j + m) << " ";
            }
            cout << '\n';
        }
    }
}