#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (m == 3) {
        if (n == 3) {
            cout << 0 << " " << 0 << '\n';
            cout << 3 << " " << 0 << '\n';
            cout << 0 << " " << 3 << '\n';
            return 0;
        }
        if (n == 4) {
            cout << 0 << " " << 0 << '\n';
            cout << 3 << " " << 0 << '\n';
            cout << 0 << " " << 3 << '\n';
            cout << 1 << " " << 1 << '\n';
            return 0;
        }
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        cout << i << " " << 10000 + i * i<< '\n';
    }
    for (int i = 1; i <= n - m; i++) {
        cout << -i << " " << -10000 - i * i << '\n';
    }
    return 0;
}