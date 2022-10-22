#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int h, w;
        cin >> h >> w;

        vector<vector<int>> best, tmp;
        int best_value = -1;

        vector<pii> st = {{1, 0}, {0, 0}, {0, 1}};
        vector<pii> dirs = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};

        int steps = 2 * (h + w);

        for (auto [si, sj] : st) {
            tmp.assign(h, vector<int>(w, 0));

            auto can = [&](int i, int j) -> bool {
                if (i < 0 || i >= h || j < 0 || j >= w)
                    return false;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ti = i + di;
                        int tj = j + dj;
                        if (ti < 0 || ti >= h || tj < 0 || tj >= w)
                            continue;
                        if (tmp[ti][tj])
                            return false;
                    }
                }
                return true;
            };

            int i = si, j = sj, curdir = 0;
            int tmp_value = 0;

            for (int it = 0; it < steps; it++) {
                if (can(i, j)) {
                    tmp_value++;
                    tmp[i][j] = 1;
                }
                while (1) {
                    auto [di, dj] = dirs[curdir];
                    int ti = i + di, tj = j + dj;
                    if (ti < 0 || ti >= h || tj < 0 || tj >= w) {
                        curdir = (curdir + 1) % 4;
                        continue;
                    }
                    i = ti, j = tj;
                    break;
                }
            }

            if (tmp_value > best_value) {
                best_value = tmp_value;
                best = tmp;
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                cout << best[i][j];
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}