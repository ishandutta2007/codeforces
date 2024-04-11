#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 998244353;

void solve() {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dist1 = rd >= rb ? rd - rb : (n - rb) + (n - rd);
    int dist2 = cd >= cb ? cd - cb : (m - cb) + (m - cd);
    cout << min(dist1, dist2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}