#include <bits/stdc++.h>
using namespace std;

bool occ[22][360];
bool bk[22][360];
bool done[22][360];

static inline int rd(int x) {
    if (x < 0) return x + 360;
    if (x >= 360) return x - 360;
    return x;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int kase; cin >> kase;
    while (kase--) {
        memset(occ, 0, sizeof(occ));
        memset(bk, 0, sizeof(bk));
        memset(done, 0, sizeof(done));
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            string op; cin >> op;
            if (op[0] == 'C') {
                int r, t1, t2;
                cin >> r >> t1 >> t2;
                if (t1 < t2) {
                    for (int t = t1; t < t2; ++t)
                        occ[r][t] = true;
                } else {
                    for (int t = t1; t < 360; ++t)
                        occ[r][t] = true;
                    for (int t = 0; t < t2; ++t)
                        occ[r][t] = true;
                }
            } else {
                int r1, r2, t;
                cin >> r1 >> r2 >> t;
                for (int r = r1 + 1; r <= r2; ++r)
                    bk[r][t] = true;
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < 360; ++i) {
            q.emplace(1, i);
            done[1][i] = true;
        }
        bool good = false;
        while (not q.empty()) {
            auto [r, t] = q.front();
            q.pop();
            if (r == 21) {
                good = true;
                break;
            }
            if (r > 1 and not occ[r - 1][t] and not done[r - 1][t]) {
                q.emplace(r - 1, t);
                done[r - 1][t] = true;
            }
            if (not occ[r][t] and not done[r + 1][t]) {
                q.emplace(r + 1, t);
                done[r + 1][t] = true;
            }
            if (int tt = rd(t + 1); not done[r][tt] and not bk[r][tt]) {
                q.emplace(r, tt);
                done[r][tt] = true;
            }
            if (int tt = rd(t - 1); not done[r][tt] and not bk[r][t]) {
                q.emplace(r, tt);
                done[r][tt] = true;
            }
        }
        //for (int i = 0; i < 360; i += 5)
        //    cout << setw(3) << i << ' ';
        //cout << '\n';
        //for (int i = 2; i <= 3; ++i) {
        //    for (int j = 0; j < 360; j += 5)
        //        cout << setw(3) << done[i][j] << " "; 
        //    cout << '\n';
        //}
        cout << (good ? "YES" : "NO") << '\n';
    }
    return 0;
}