#include <bits/stdc++.h>
using namespace std;

const int M = 35, N = 35;

int te, n, m, cnt[N + M][2];

void solve() {
    cin >> m >> n;
    for (int i = 2; i <= m + n; i++) {
        cnt[i][0] = cnt[i][1] = 0;
    }
    int ans = 0, u;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> u;
            cnt[i + j][u]++;
        }
    }
    for (int i = 2, j = m + n; i < j; i++, j--) {
        ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        solve();
    }
}