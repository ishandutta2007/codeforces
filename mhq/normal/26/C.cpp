#include <bits/stdc++.h>
using namespace std;
int a1, b1, c1;
int n, m;
int a[125][125];
int b[125][125];
int ans[(int)1e5 + 10];
int c[125][125];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a1 >> b1 >> c1;
    if ((n * m) % 2 != 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if (n == 1) {
        if (a1 < (m / 2)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        for (int i = 1; i <= m; i++) {
            cout << (char)(((i - 1) / 2) % 10 + 'a');
        }
        return 0;
    }
    if (m == 1) {
        if (b1 < (n / 2)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            cout << (char)(((i - 1) / 2) % 10 + 'a') << '\n';
        }
        return 0;
    }
    bool ok = true;
    if (n % 2 != 0) {
        ok = false;
        swap(n, m);
        swap(a1, b1);
    }
    int rm = m;
    for (int i = 1; i <= 120; i++) {
        for (int j = 1; j <= 120; j++) {
            if (i > n || j > m) a[i][j] = -1;
        }
    }
    int sz = 1;
    if (m % 2 == 1) {
        if (b1 < (n / 2)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        for (int i = 1; i <= n; i += 2) {
            a[i][m] = sz;
            a[i + 1][m] = sz;
            sz++;
            b1--;
        }
        m--;
    }
    a1 = (a1 - (a1 % 2));
    b1 = (b1 - (b1 % 2));
    if (2 * a1 + 2 * b1 + 4 * c1 < n * m) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int S = n * m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0 && a[i][j + 1] == 0 && a[i + 1][j] == 0 && a[i + 1][j + 1] == 0) {
                if (a1 > 0) {
                    a[i][j] = sz;
                    a[i][j + 1] = sz;
                    a[i + 1][j] = sz + 1;
                    a[i + 1][j + 1] = sz + 1;
                    sz += 2;
                    a1 -= 2;
                }
                else if (b1 > 0) {
                    a[i][j] = sz;
                    a[i + 1][j] = sz;
                    a[i][j + 1] = sz + 1;
                    a[i + 1][j + 1] = sz + 1;
                    sz += 2;
                    b1 -= 2;
                }
                else {
                    a[i][j] = sz;
                    a[i + 1][j] = sz;
                    a[i][j + 1] = sz;
                    a[i + 1][j + 1] = sz;
                    sz += 1;
                    c1--;
                }
            }
        }
    }
    m = rm;
    if (ok) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                b[i][j] = a[i][j];
            }
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                b[j][i] = a[i][j];
            }
        }
        swap(n, m);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t = b[i][j];
            if (ans[t] != 0) {
                c[i][j] = ans[t];
            }
            else {
                ans[t] = ((i + 5 * j) % 26) + 1;
                c[i][j] = ans[t];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (char)((c[i][j] - 1) + 'a');
        }
        cout << '\n';
    }
    return 0;
}