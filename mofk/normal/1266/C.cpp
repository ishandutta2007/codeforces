#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) return cout << 0 << endl, 0;
    if (m == 1) {
        for (int i = 1; i <= n; ++i) cout << i + 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = n + 1; j <= n + m; ++j) cout << i * j << ' ';
        cout << endl;
    }
    return 0;
}