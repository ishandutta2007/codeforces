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
    // #define DEBUG

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

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
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
#define pb push_back
#define eb emplace_back

int n, k;
vector<string> table;
vector<char> row, col;
vector<vector<char>> row_left, row_right, col_up, col_down;
vector<vector<int>> fr_row, cnt_row;

void calc() {
    row.resize(n);
    for (int i = 0; i < n; i++) {
        bool chk = true;
        for (int j = 0; j < n; j++)
            chk &= (table[i][j] == 'W');
        row[i] = chk;
    }
    col.resize(n);
    for (int j = 0; j < n; j++) {
        bool chk = true;
        for (int i = 0; i < n; i++)
            chk &= (table[i][j] == 'W');
        col[j] = chk;
    }
    row_left.resize(n, vector<char>(n, 0));
    row_right.resize(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++) {
        if (row[i]) {
            row_left[i] = vector<char>(n, 1);
            row_right[i] = vector<char>(n, 1);
            continue;
        }
        int L = 0, R = n - 1;
        while (table[i][L] == 'W')
            L++;
        while (table[i][R] == 'W')
            R--;
        for (int j = 0; j < L; j++)
            row_left[i][j] = 1;
        for (int j = R + 1; j < n; j++)
            row_right[i][j] = 1;
    }
    col_up.resize(n, vector<char>(n, 0));
    col_down.resize(n, vector<char>(n, 0));
    for (int j = 0; j < n; j++) {
        if (col[j]) {
            col_up[j] = vector<char>(n, 1);
            col_down[j] = vector<char>(n, 1);
            continue;
        }
        int L = 0, R = n - 1;
        while (table[L][j] == 'W')
            L++;
        while (table[R][j] == 'W')
            R--;
        for (int i = 0; i < L; i++)
            col_up[j][i] = 1;
        for (int i = R + 1; i < n; i++)
            col_down[j][i] = 1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    table.resize(n);
    for (auto &el : table)
        cin >> el;
    calc();
    auto chk_col = [&](int i, int j) {
        bool ok = true;
        if (i != 0)
            ok &= col_up[j][i - 1];
        if (i + k < n)
            ok &= col_down[j][i + k];
        debug("chk_col", i, j, ok);
        return ok;
    };
    auto chk_row = [&](int i, int j) {
        bool ok = true;
        if (j != 0)
            ok &= row_left[i][j - 1];
        if (j + k < n)
            ok &= row_right[i][j + k];
        debug("chk_row", i, j, ok);
        return ok;
    };
    fr_row.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            fr_row[i][j] = chk_row(i, j);
    cnt_row.resize(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= n - k; i--)
            cnt_row[n - k][j] += fr_row[i][j];
        for (int i = n - k - 1; i >= 0; i--) {
            cnt_row[i][j] = cnt_row[i + 1][j];
            cnt_row[i][j] -= fr_row[i + k][j];
            cnt_row[i][j] += fr_row[i][j];
        }
    }
    debug(cnt_row);
    int ans = 0;
    int cnt_roww = 0;
    for (int i = k; i < n; i++)
        cnt_roww += row[i];
    for (int i = 0; i + k - 1 < n; i++) {
        debug(i, cnt_roww);
        int cnt_col = 0;
        for (int j = k; j < n; j++)
            cnt_col += col[j];
        int opt = 0;
        for (int j = 0; j < k; j++)
            opt += chk_col(i, j);
        opt += cnt_row[i][0];
        debug("start", i, opt);
        for (int j = 0; j + k - 1 < n; j++) {
            ans = max(ans, opt + cnt_roww + cnt_col);
            opt -= cnt_row[i][j];
            if (j + 1 < n)
                opt += cnt_row[i][j + 1];
            opt -= chk_col(i, j);
            if (j + k < n)
                opt += chk_col(i, j + k);
            cnt_col += col[j];
            if (j + k < n)
                cnt_col -= col[j + k];
        }
        cnt_roww += row[i];
        if (i + k < n)
            cnt_roww -= row[i + k];
    }
    cout << ans << '\n';
}