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
        vector<string> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int x = -1, y = -1;
        char c = '.';
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (a[i][j] != '.') {
            x = i; y = j; c = a[i][j];
        }
        if (x == -1) x = 0, y = 0, c = 'R';
        int bad = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            char d;
            if ((i + j + x + y) % 2 == 0) d = c; else d = 'R' ^ 'W' ^ c;
            if (a[i][j] != '.' && a[i][j] != d) bad = 1;
            a[i][j] = d;
        }
        if (bad) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) cout << a[i] << endl;
        }
    }
    return 0;
}