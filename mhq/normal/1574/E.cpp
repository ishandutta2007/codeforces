#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int n, m, k;
const int maxN = 1e6 + 15;
int pw2[maxN];
int row[2][maxN];
int col[2][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    pw2[0] = 1;
    for (int i = 1; i < maxN; i++) pw2[i] = mult(2, pw2[i - 1]);
    int bad[2] = {0, 0};
    int free_row = n;
    int free_col = m;
    int bad_row = 0;
    int bad_col = 0;
    auto upd = [&](int x, int y, int tp, int z) {
        if (tp != -1) {
            bad[(x + y + tp) % 2] += z;
            free_row += ((row[0][x] || row[1][x]) > 0);
            bad_row -= (row[0][x] && row[1][x]);
            free_col += ((col[0][y] || col[1][y]) > 0);
            bad_col -= (col[0][y] && col[1][y]);
            row[(y + tp) % 2][x] += z;
            col[(x + tp) % 2][y] += z;
            free_row -= ((row[0][x] || row[1][x]) > 0);
            bad_row += (row[0][x] && row[1][x]);
            free_col -= ((col[0][y] || col[1][y]) > 0);
            bad_col += (col[0][y] && col[1][y]);
        }

    };
    map<pair<int,int>,int> mp;
    while (k--) {
        int x, y, tp;
        cin >> x >> y >> tp;
        if (!mp.count({x, y})) {
            mp[{x, y}] = -1;
        }
        int was = mp[{x, y}];
        upd(x, y, was, -1);
        mp[{x, y}] = tp;
        upd(x, y, tp, +1);
        int ans = 0;
        if (bad_row == 0) {
            ans = sum(ans, pw2[free_row]);
        }
        if (bad_col == 0) {
            ans = sum(ans, pw2[free_col]);
        }
//        cout << free_row << " " << free_col << " " << bad[0] << " " << bad[1] << endl;
        if (!bad[0]) ans = sub(ans, 1);
        if (!bad[1]) ans = sub(ans, 1);
        cout << ans << '\n';
    }
    return 0;
}