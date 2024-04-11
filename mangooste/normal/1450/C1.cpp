#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &s : grid) {
        cin >> s;
    }

    array<int, 3> cntX{0, 0, 0};
    array<int, 3> cntO{0, 0, 0};
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int col = (i + j) % 3;
            if (grid[i][j] == 'X') cntX[col]++;
            if (grid[i][j] == 'O') cntO[col]++;
            k += grid[i][j] == 'X' || grid[i][j] == 'O';
        }
    }

    bool already = false;
    for (int x = 0; x < 3 && !already; x++) {
        for (int o = 0; o < 3; o++) {
            if (x == o) continue;
            if (cntO[x] + cntX[o] > k / 3) continue;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int col = (i + j) % 3;
                    if (col == x && grid[i][j] == 'O') grid[i][j] = 'X';
                    if (col == o && grid[i][j] == 'X') grid[i][j] = 'O';
                }
            }

            already = true;
            break;
        }
    }
    assert(already);

    for (auto s : grid) {
        cout << s << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}