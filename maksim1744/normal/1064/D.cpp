/*
    19.10.2018 17:30:07
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

typedef pair<int, int> pi;

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;
    int r, c;
    cin >> r >> c;
    --r; --c;
    int x, y;
    cin >> x >> y;
    int field[n][m];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c != '*') {
                field[i][j] = count;
                ++count;
            } else {
                field[i][j] = -1;
            }
        }
    }
    // vector< vector< int > > g(count);
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         if (field[i][j] == -1) {
    //             continue;
    //         }
    //         if (i != 0) {
    //             if (field[i - 1][j] != -1) {
    //                 g[field[i][j]].push_back(field[i - 1][j]);
    //             }
    //         }
    //         if (j != 0) {
    //             if (field[i][j - 1] != -1) {
    //                 g[field[i][j]].push_back(field[i][j - 1]);
    //             }
    //         }
    //         if (i != n - 1) {
    //             if (field[i + 1][j] != -1) {
    //                 g[field[i][j]].push_back(field[i + 1][j]);
    //             }
    //         }
    //         if (j != 0) {
    //             if (field[i][j + 1] != -1) {
    //                 g[field[i][j]].push_back(field[i][j + 1]);
    //             }
    //         }
    //     }
    // }
    vector< pi > now;
    now.push_back({r, c});
    vector< vector< int > > d(n);
    for (int i = 0; i < n; ++i) {
        d[i].assign(m, 1000000000);
    }
    d[r][c] = 0;
    int i = r - 1;
    while (i >= 0 && field[i][c] != -1) {
        d[i][c] = 0;
        now.push_back({i, c});
        --i;
    }
    i = r + 1;
    while (i < n && field[i][c] != -1) {
        d[i][c] = 0;
        now.push_back({i, c});
        ++i;
    }
    while (now.size() > 0) {
        vector< pi > next;
        for (auto item : now) {
            if (item.second > 0 && field[item.first][item.second - 1] != -1 &&
                                d[item.first][item.second - 1] > d[item.first][item.second] + 1) {
                d[item.first][item.second - 1] = d[item.first][item.second] + 1;
                next.push_back({item.first, item.second - 1});
            }
            if (item.second < m - 1 && field[item.first][item.second + 1] != -1 &&
                                d[item.first][item.second + 1] > d[item.first][item.second] + 1) {
                d[item.first][item.second + 1] = d[item.first][item.second] + 1;
                next.push_back({item.first, item.second + 1});
            }
        }
        now = next;
        for (auto item : now) {
            int i = item.first - 1;
            int dn = d[item.first][item.second];
            while (i >= 0 && d[i][item.second] > dn && field[i][item.second] != -1) {
                d[i][item.second] = dn;
                next.push_back({i, item.second});
                --i;
            }
            i = item.first + 1;
            while (i < n && d[i][item.second] > dn && field[i][item.second] != -1) {
                d[i][item.second] = dn;
                next.push_back({i, item.second});
                ++i;
            }
        }
        swap(now, next);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i][j] == 1000000000) {
                continue;
            }
            // l + r = d
            // r - l = j - c
            int r = (d[i][j] + j - c) / 2;
            int l = d[i][j] - r;
            if (l <= x && r <= y) {
                ++ans;
            }
        }
    }
    // for (auto item : d) {
    //     for (auto elem : item) {
    //         if (elem == 1000000000) {
    //             cout << "- ";
    //         } else {
    //             cout << elem << ' ';
    //         }
    //     }
    //     cout << '\n';
    // }
    cout << ans << '\n';
    return 0;
}