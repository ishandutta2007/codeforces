#include<bits/stdc++.h>
using namespace std;
const int nax = 512;
int64_t a[nax][nax];
int n;

void solve() {
    cin >> n;
    int64_t sum = 0;
    for (int i = 0 ; i < 2 * n ; ++ i) {
        for (int j = 0 ; j < 2 * n ; ++ j) {
            cin >> a[i][j];
            if (i >= n && j >= n)
                sum += a[i][j];
        }
    }
    int64_t mn = 1e18;
    vector <pair <int ,int>> corner;
    corner.emplace_back(0, 0);
    corner.emplace_back(0, n - 1);
    corner.emplace_back(n - 1, 0);
    corner.emplace_back(n - 1, n - 1);
    for (int i = 0 ; i < 2 ; ++ i) {
        int ax = i ? 0 : n, ay = i ? n : 0;
        for (auto [u, v] : corner) {
            mn = min(mn, a[u + ax][v + ay]);
        }
    }
    sum += mn;
    cout << sum << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ;T -- ; ) {
        solve();
    }
}