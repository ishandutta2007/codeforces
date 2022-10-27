#include<bits/stdc++.h>
using namespace std;
const int nax = 512;

int n, m;
int a[nax][nax];
int sp[nax * 2];
int sm[nax * 2];


void solve() {
    cin >> n >> m;
    memset(sp, 0, sizeof(sp));
    memset(sm, 0, sizeof(sm));
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            cin >> a[i][j];
            sp[i + j] += a[i][j];
            sm[nax + i - j] += a[i][j];
        }
    }
    int ans = 0;

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        ans = max(ans, sp[i + j] + sm[nax + i - j] - a[i][j]);
    }
    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
        //cout << (solve() ? "YES" : "NO") << '\n';
    }
}