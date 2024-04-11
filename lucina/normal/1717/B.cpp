#include<bits/stdc++.h>
using namespace std;
const int nax = 1024;
int n, k, r, c;
char ans[nax][nax];
char b[nax][nax];

void solve() {
    cin >> n >> k >> r >> c;
    r -= 1, c -= 1;

    for (int i = 0 ; i < 2 * n ; ++ i) {
        for (int j = 0 ; j < 2 * n ; ++ j) {
            ans[i][j] = '.';
        }
    }

    for (int i = 0 ; i < 2 * n ; i += k) {
        for (int j = 0 ; j < 2 * n ; j += k) {
            int si = i, sj = j;
            for (int v = 0 ; v < k ; ++ v) {
                ans[si][sj] = 'X';
                si += 1;
                sj += 1;
            }
        }
    }

    int shift = 0;
    if (ans[r][c] != 'X') {
        int rc = (c / k) * k;
        while (ans[r][rc] != 'X') rc += 1;
        shift = (rc - c + k) % k;
    }

    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            cout << ans[i][(j + shift)];
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }

}