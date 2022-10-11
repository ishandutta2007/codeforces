#include <bits/stdc++.h>
using namespace std;

const int M = 65, N = 65;

int t, m, n;
char s[M][N];

void solve() {
    cin >> m >> n;
    int ca = 0, cp = 0, ans = N;
    for (int i = 1; i <= m; i++) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= n; j++) {
            ca += (s[i][j] == 'A');
            cp += (s[i][j] == 'P');
            if (s[i][j] == 'A') {
                int ho = (i == 1 || i == m);
                int ve = (j == 1 || j == n);
                if (ho && ve) {
                    ans = min(ans, 2);
                } else if (ho || ve) {
                    ans = min(ans, 3);
                } else {
                    ans = min(ans, 4);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int c = 0;
        for (int j = 1; j <= n; j++) {
            c += (s[i][j] == 'A');
        }
        if (c == n) {
            if (i == 1 || i == m) {
                ans = min(ans, 1);
            } else {
                ans = min(ans, 2);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int c = 0;
        for (int j = 1; j <= m; j++) {
            c += (s[j][i] == 'A');
        }
        if (c == m) {
            if (i == 1 || i == n) {
                ans = min(ans, 1);
            } else {
                ans = min(ans, 2);
            }
        }
    }
    if (cp == 0) {
        ans = min(ans, 0);
    }
    if (ans == N) {
        cout << "MORTAL\n";
    } else {
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}