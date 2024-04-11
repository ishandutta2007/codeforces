#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n, string(m, '0'));
        a[0][0] = '1';
        a[0][m-1] = '1';
        a[n-1][0] = '1';
        a[n-1][m-1] = '1';
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (i != 0 && i != n - 1 && j != 0 && j != m - 1) continue;
            if (a[i][j] == '1') continue;
            int fl = 1;
            for (int x = i-1; x <= i+1; ++x) for (int y = j-1; y <= j+1; ++y) if (0 <= x && x < n && 0 <= y && y < m && a[x][y] == '1') fl = 0;
            if (fl) a[i][j] = '1';
        }
        for (int i = 0; i < n; ++i) cout << a[i] << '\n';
        cout << endl;
    }
    return 0;
}