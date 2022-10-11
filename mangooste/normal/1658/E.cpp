#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> tot;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            tot.push_back({x, i, j});
        }
    }
    sort(all(tot));
    reverse(all(tot));

    array<array<int, 4>, 4> mx;
    mx.fill({-n, -n, -1, -1});
    vector win(n, vector<bool>(n, true));
    for (auto &[_, x, y] : tot) {
        for (int mask = 0; mask < 4; mask++) {
            if (mx[mask][0] == -n) continue;
            if (abs(mx[mask][2] - x) + abs(mx[mask][3] - y) > k) {
                win[x][y] = false;
                break;
            }
        }
        if (!win[x][y]) continue;
        for (int mask = 0; mask < 4; mask++) {
            int cur_x = (mask & 1) ? x : -x;
            int cur_y = (mask >> 1 & 1) ? y : -y;
            if (mx[mask][0] == -n || mx[mask][0] + mx[mask][1] < cur_x + cur_y) {
                mx[mask] = {cur_x, cur_y, x, y};
            }
        }
    }

    for (int i = 0; i < n; i++, cout << '\n') {
        for (int j = 0; j < n; j++) {
            cout << "GM"[win[i][j]];
        }
    }
}