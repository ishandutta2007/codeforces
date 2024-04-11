#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
int n, m;
char s[nax][nax];

void solve() {
    cin >> n >> m;
    int ans = 0;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> s[i];
        ans += count(s[i], s[i] + m, '1');
    }

    if (ans == n * m) {
        cout << ans - 2 << '\n';
        return;
    }

    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            if (s[i][j] == '0' && j + 1 < m && s[i][j + 1] == '0') {
                cout << ans << '\n';
                return;
            }
            if (s[i][j] == '0' && i + 1 < n && s[i + 1][j] == '0') {
                cout << ans << '\n';
                return;
            }
            if (s[i][j] == '0' && i + 1 < n && j > 0 && s[i + 1][j - 1] == '0') {
                cout << ans << '\n';
                return;
            }
            if (s[i][j] == '0' && i + 1 < n && j + 1 < m && s[i + 1][j + 1] == '0') {
                cout << ans << '\n';
                return;
            }
        }
    }
    cout << ans - 1 << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}