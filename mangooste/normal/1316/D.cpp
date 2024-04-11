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

int n;
vector<vector<pii>> to;
vector<vector<char>> ans;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
set<pii> maybe;

char get_rev(int d) {
    if (d == -1)
        return 'X';
    if (d == 0)
        return 'L';
    if (d == 1)
        return 'R';
    if (d == 2)
        return 'U';
    return 'D';
}

char get_norm(int d) {
    if (d == -1)
        return 'X';
    if (d == 0)
        return 'R';
    if (d == 1)
        return 'L';
    if (d == 2)
        return 'D';
    return 'U';
}

bool ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs_go(int x, int y, pii need, int frm) {
    ans[x][y] = get_rev(frm);
    for (int d = 0; d < 4; d++) {
        int X = x + dx[d];
        int Y = y + dy[d];
        if (ok(X, Y) && to[X][Y] == need && ans[X][Y] == 'Q')
            dfs_go(X, Y, need, d);
    }
}

bool dfs_cycle(int x, int y) {
    bool fnd = false;
    for (int d = 0; d < 4; d++) {
        int X = x + dx[d];
        int Y = y + dy[d];
        if (!ok(X, Y) || to[X][Y] != mp(-1, -1))
            continue;
        if (ans[X][Y] == 'Q') 
            ans[X][Y] = get_rev(d), ans[x][y] = get_norm(d);
        else
            ans[x][y] = get_norm(d);
        fnd = true;
        maybe.erase(mp(X, Y));
        break;
    }
    return fnd;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    to.resize(n, vector<pii>(n));
    ans.resize(n, vector<char>(n, 'Q'));
    for (auto &i : to)
        for (auto &el : i) {
            cin >> el.first >> el.second;
            if (el != mp(-1, -1))
                el.first--, el.second--;
        }
    bool fnd = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (to[i][j] == mp(i, j))
                dfs_go(i, j, to[i][j], -1);
    bool chk = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (ans[i][j] == 'Q') {
                chk &= (to[i][j] == mp(-1, -1));
                maybe.insert(mp(i, j));
            }
    if (!chk)
        return cout << "INVALID\n", 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cerr << ans[i][j];
    //     cerr << '\n';
    // }
    while (!maybe.empty()) {
        pii cur = *maybe.begin();
        maybe.erase(maybe.begin());
        if (!dfs_cycle(cur.first, cur.second))
            return cout << "INVALID\n", 0;
    }
    cout << "VALID\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j];
        cout << '\n';
    }
}