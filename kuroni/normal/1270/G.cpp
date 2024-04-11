#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int t, n, f[N], vis[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        f[i] = i - f[i];
        vis[i] = 0;
    }
    int pos = 1, cur = 1, ans;
    do {
        vis[pos] = cur++;
        pos = f[pos];
    } while (vis[pos] == 0);
    ans = cur - vis[pos];
    cout << ans << '\n';
    for (int i = 0; i < ans; i++, pos = f[pos]) {
        cout << pos << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}