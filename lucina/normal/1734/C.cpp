#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n;
int mn_cst[nax];
string s;

void solve() {
    cin >> n >> s;
    s = '#' + s;
    iota(mn_cst, mn_cst + 1 + n, 0);
    int64_t ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (s[i] == '1') continue;
        ans += mn_cst[i];
        for (int j = i + i ; j <= n ; j += i) {
            if (s[j] == '1') break;
            mn_cst[j] = min(mn_cst[j], i);
        }
    }

    cout << ans << '\n';
    /**
        we can choose only number in S - T
    */

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}