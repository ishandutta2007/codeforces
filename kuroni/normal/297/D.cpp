#include <bits/stdc++.h>
using namespace std;

const int M = 1005, N = 1005;

int m, n, k, a[M][N];
bool fl;
string s[2 * M], t[2 * M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> k;
    for (int i = 0; i < 2 * m - 1; i++) {
        cin >> s[i];
    }
    if (k == 1) {
        int cnt = 0, tot = 0;
        for (int i = 0; i < 2 * m - 1; i++) {
            tot += s[i].size();
            for (char &c : s[i]) {
                cnt += (c == 'E');
            }
        }
        if (cnt * 4 >= tot * 3) {
            cout << "YES\n";
            for (int i = 0; i < m; i++, cout << '\n') {
                for (int j = 0; j < n; j++) {
                    cout << "1 ";
                }
            }
        } else {
            cout << "NO\n";
        }
        return 0;
    }
    if (m > n) {
        fl = true;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                t[2 * i] += s[2 * j - 1][i];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[2 * i - 1] += s[2 * j][i - 1];
            }
        }
        swap(m, n);
        for (int i = 0; i < 2 * m - 1; i++) {
            s[i] = t[i];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] = a[i][j - 1] ^ (s[2 * i][j - 1] == 'N');
        }
        if (i == 0) {
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += ((a[i][j] == a[i - 1][j]) ^ (s[2 * i - 1][j] == 'N'));
        }
        if (cnt <= n / 2) {
            for (int j = 0; j < n; j++) {
                a[i][j] ^= 1;
            }
        }
    }
    cout << "YES\n";
    if (!fl) {
        for (int i = 0; i < m; i++, cout << '\n') {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] + 1 << " ";
            }
        }
    } else {
        for (int i = 0; i < n; i++, cout << '\n') {
            for (int j = 0; j < m; j++) {
                cout << a[j][i] + 1 << " ";
            }
        }
    }
}