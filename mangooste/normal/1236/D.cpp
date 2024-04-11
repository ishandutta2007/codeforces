#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

int n, m, k;
ll need;
vector<vector<int>> row, col;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int mn_x, mx_x, mn_y, mx_y;

inline void GG(bool chk = false) {
    cout << (chk ? "Yes\n" : "No\n");
    exit(0);
}

ll go(int x, int y, int d = 0) {
    // cerr << "go(x, y, d) " << x << ' ' << y << ' ' << d << endl;
    if (d == 4)
        d = 0;
    if (d == 0) {
        int pos = lower_bound(all(row[x]), y) - row[x].begin();
        int to_y;
        if (pos == row[x].size())
            to_y = mx_y - 1;
        else
            to_y = min(row[x][pos], mx_y) - 1;
        ll cur = to_y - y;
        mx_y = to_y;
        if (to_y == y && !(mp(x, y) == mp(0, 0)))
            return 0;
        return cur + go(x, to_y, d + 1); 
    } else if (d == 1) {
        int pos = lower_bound(all(col[y]), x) - col[y].begin();
        int to_x;
        if (pos == col[y].size())
            to_x = mx_x - 1;
        else
            to_x = min(mx_x, col[y][pos]) - 1;
        ll cur = to_x - x;
        mx_x = to_x;
        if (to_x == x)
            return 0;
        return cur + go(to_x, y, d + 1);
    } else if (d == 2) {
        int pos = lower_bound(all(row[x]), y) - row[x].begin() - 1;
        int to_y;
        if (pos == -1)
            to_y = mn_y + 1;
        else
            to_y = max(mn_y, row[x][pos]) + 1;
        ll cur = y - to_y;
        mn_y = to_y;
        if (to_y == y)
            return 0;
        return cur + go(x, to_y, d + 1);
    } else {
        int pos = lower_bound(all(col[y]), x) - col[y].begin() - 1;
        int to_x;
        if (pos == -1)
            to_x = mn_x + 1;
        else
            to_x = max(col[y][pos], mn_x) + 1;
        ll cur = x - to_x;
        mn_x = to_x;
        if (to_x == x)
            return 0;
        return cur + go(to_x, y, d + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    need = 1ll * n * m - k;
    row.resize(n);
    col.resize(m);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        row[x].pb(y);
        col[y].pb(x);
    }
    for (auto &el : row)
        sort(all(el));
    for (auto &el : col)
        sort(all(el));
    mn_x = 0, mx_x = n, mn_y = -1, mx_y = m;
    GG(go(0, 0) + 1 == need);
}