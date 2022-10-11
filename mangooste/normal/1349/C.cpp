#include <algorithm>
#include <cassert>
#include <cmath>
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

struct node {
    int x, y, cur_col, cnt;
    node(int x = -1, int y = -1, int cur_col = 0, int cnt = 0) :
        x(x), y(y), cur_col(cur_col), cnt(cnt)
    {}
};

int n, m, t;
vector<vector<int>> table, cmp_num, first_time;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
vector<int> sz;
int cur_num = 0;

bool Ok(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Dfs(int x, int y) {
    cmp_num[x][y] = cur_num;
    sz.back()++;
    first_time[x][y] = 0;
    for (int d = 0; d < 4; d++) {
        int X = x + dx[d];
        int Y = y + dy[d];
        if (!Ok(X, Y) || cmp_num[X][Y] != -1 || table[x][y] != table[X][Y])
            continue;
        Dfs(X, Y);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> t;
    table.resize(n, vector<int>(m, 0));
    for (auto &i : table)
        for (auto &el : i) {
            char cur;
            cin >> cur;
            el = cur - '0';
        }
    cmp_num.resize(n, vector<int>(m, -1));
    first_time.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (cmp_num[i][j] == -1) {
                // cerr << "i, j = " << i << ' ' << j << endl;
                sz.pb(0);
                Dfs(i, j);
                cur_num++;
            }
    deque<node> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sz[cmp_num[i][j]] != 1)
                q.pb(node(i, j, table[i][j], 0));
            else
                first_time[i][j] = -1;
    while (!q.empty()) {
        node cur = q.front();
        q.pop_front();
        int x = cur.x, y = cur.y, dst = cur.cnt, cur_col = cur.cur_col;
        for (int d = 0; d < 4; d++) {
            int X = x + dx[d];
            int Y = y + dy[d];
            if (!Ok(X, Y))
                continue;
            int cur_fir = 0;
            if (table[X][Y] != cur_col)
                cur_fir = dst + 1;
            else
                cur_fir = dst;
            if (first_time[X][Y] == -1 || first_time[X][Y] > cur_fir) {
                first_time[X][Y] = cur_fir;
                if (first_time[X][Y] == dst)
                    q.push_front(node(X, Y, table[X][Y], first_time[X][Y]));
                else
                    q.pb(node(X, Y, table[X][Y], first_time[X][Y]));
            }
        }
    }
    // cerr << "first_time = " << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cerr << first_time[i][j] << ' ';
    //     cerr << endl;
    // }
    while (t--) {
        int x, y;
        ll p;
        cin >> x >> y >> p, x--, y--;
        // cerr << "first_time = " << first_time[x][y] << endl;
        if (first_time[x][y] == -1 || p <= first_time[x][y]) {
            cout << table[x][y] << '\n';
            continue;
        }
        ll del = p - first_time[x][y];
        // cerr << "del = " << del << endl;
        if (del % 2 == 1)
            cout << (table[x][y] ^ 1) << '\n';
        else
            cout << table[x][y] << '\n';
    }
}