/*
    16.03.2019 16:54:39
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int n;
vector< string > field;
int color;
vector< vector< int > > col;

bool check(pair< int, int > p) {
    if (p.first < 0 || p.first >= n || p.second < 0 || p.second >= n)
        return false;
    return true;
}

vector< pair< int, int > > to(pair< int, int > from) {
    vector< pair< int, int > > ans;
    for (auto [di, dj] : vector< pair< int, int > >{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
        auto p = from;
        p.first += di;
        p.second += dj;
        if (check(p))
            ans.push_back(p);
    }
    return ans;
}

void dfs(pair< int, int > v) {
    col[v.first][v.second] = color;
    for (auto p : to(v)) {
        if (col[p.first][p.second] == -1)
            dfs(p);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            auto p = make_pair(i, j);
            show(p, to(p));
        }
    }
    field.resize(n);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1; --c1; --r2; --c2;
    col.assign(n, vector< int >(n, -1));
    for (int i = 0; i < n; ++i) {
        cin >> field[i];
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == '1')
                col[i][j] = 0;
        }
    }
    color = 3;
    dfs({r1, c1});
    if (col[r2][c2] == color) {
        cout << 0 << '\n';
        return 0;
    }
    color = 4;
    dfs({r2, c2});
    int ans = 1000000000;
    for (int x1 = 0; x1 < n; ++x1) {
        for (int y1 = 0; y1 < n; ++y1) {
            for (int x2 = 0; x2 < n; ++x2) {
                for (int y2 = 0; y2 < n; ++y2) {
                    if (col[x1][y1] == 3 && col[x2][y2] == 4)
                        ans = min(ans, (((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))));
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}