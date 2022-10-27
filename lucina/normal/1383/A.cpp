#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;
char a[nax], b[nax];
int ct[21][21];
int n;

void solve() {
    cin >> n;
    cin >> a + 1 >> b + 1;
    memset(ct, 0, sizeof(ct));
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] > b[i]) {
            cout << "-1\n";
            return;
        }

        if (a[i] == b[i]) continue;
        ct[a[i] - 'a'][b[i] - 'a'] ++;
    }
    int ans = 0;

    for (int i = 0 ; i < 20 ; ++ i) {
        int to_sent = -1;
        for (int j = i + 1 ; j < 20 ; ++ j) {
            if (ct[i][j] > 0) {
                to_sent = j;
                break;
            }
        }
        if (to_sent != -1) {
            ++ ans;
            for (int j = to_sent + 1 ; j < 20 ; ++ j) {
                ct[to_sent][j] += ct[i][j];
            }
        }
    }

    cout << ans << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;

    for (; T -- ;) {
        solve();
    }

}
/*
    Good Luck
        -Lucina
*/