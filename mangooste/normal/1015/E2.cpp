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

using ll = long long;
using namespace std;

namespace Debug {
    #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()

struct star {
    int x, y, len;

    star(int x = 0, int y = 0, int len = 0) :
        x(x), y(y), len(len)
    {}
};

int n, m;
vector<string> table;
vector<vector<int>> row_left, row_right, col_up, col_down;
vector<star> ans;

void precalc() {
    row_left.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        if (table[i][0] == '.')
            row_left[i][0] = -1;
        else
            row_left[i][0] = 0;
        for (int j = 1; j < m; j++) {
            if (table[i][j] == '.')
                row_left[i][j] = -1;
            else
                row_left[i][j] = row_left[i][j - 1] + 1;
        }
    }
    row_right.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        if (table[i][m - 1] == '.')
            row_right[i][m - 1] = -1;
        else
            row_right[i][m - 1] = 0;
        for (int j = m - 2; j >= 0; j--) {
            if (table[i][j] == '.')
                row_right[i][j] = -1;
            else
                row_right[i][j] = row_right[i][j + 1] + 1;
        }
    }
    col_up.resize(m, vector<int>(n));
    for (int j = 0; j < m; j++) {
        if (table[0][j] == '.')
            col_up[j][0] = -1;
        else
            col_up[j][0] = 0;
        for (int i = 1; i < n; i++) {
            if (table[i][j] == '.')
                col_up[j][i] = -1;
            else
                col_up[j][i] = col_up[j][i - 1] + 1;
        }
    }
    col_down.resize(m, vector<int>(n));
    for (int j = 0; j < m; j++) {
        if (table[n - 1][j] == '.')
            col_down[j][n - 1] = -1;
        else
            col_down[j][n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (table[i][j] == '.')
                col_down[j][i] = -1;
            else
                col_down[j][i] = col_down[j][i + 1] + 1;
        }
    }
}

bool check() {
    vector<vector<int>> cnt_row(n, vector<int>(m + 1, 0));
    vector<vector<int>> cnt_col(m, vector<int>(n + 1, 0));
    for (auto el : ans) {
        int x = el.x, y = el.y, len = el.len;
        cnt_col[y][x - len]++;
        cnt_col[y][x + len + 1]--;
        cnt_row[x][y - len]++;
        cnt_row[x][y + len + 1]--;
    }
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0, sm = cnt_row[i][0]; j < m; j++, sm += cnt_row[i][j])
            cnt[i][j] += sm;
    for (int j = 0; j < m; j++)
        for (int i = 0, sm = cnt_col[j][0]; i < n; i++, sm += cnt_col[j][i])
            cnt[i][j] += sm;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (table[i][j] == '*' && cnt[i][j] == 0)
                return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    table.resize(n);
    for (auto &el : table)
        cin >> el;
    precalc();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (table[i][j] == '.')
                continue;
            int cur_len = min({row_left[i][j], row_right[i][j], col_up[j][i], col_down[j][i]});
            if (cur_len > 0)
                ans.push_back(star(i, j, cur_len));
        }
    if (!check())
        return cout << "-1\n", 0;
    cout << ans.size() << '\n';
    for (auto el : ans)
        cout << el.x + 1 << ' ' << el.y + 1 << ' ' << el.len << '\n';
}