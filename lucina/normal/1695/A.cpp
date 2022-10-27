#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[100][100];

void solve() {
    tuple <int, int, int> mx = make_tuple(-1e9 - 7, 0, 0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            cin >> a[i][j];
            mx = max(mx, make_tuple(a[i][j], i, j));
        }
    }
    auto [_, i, j] = mx;
    cout << max(i, n - i + 1) * max(j, m - j + 1) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}