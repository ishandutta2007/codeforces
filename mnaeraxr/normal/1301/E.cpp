#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <assert.h>

#define endl '\n'

using namespace std;

struct segment_tree {
    vector<set<int>> st;

    segment_tree(int n) {
        st = vector<set<int>>(4 * n);
    }

    void insert(int p, int b, int e, int x, int y) {
        st[p].insert(y);

        if (b + 1 == e) return;

        int m = (b + e) >> 1, l = p << 1, r = l | 1;

        if (x < m) insert(l, b, m, x, y);
        else insert(r, m, e, x, y);
    }

    bool contains(int p, int b, int e, int x, int y, int lo, int hi) {
        // cout << p << " " << b << " " << e << " " << x << " " << y << " " << lo << " " << hi << endl; cout.flush();
        
        if (x <= b && e <= y) {
            auto it = st[p].lower_bound(lo);
            if (it == st[p].end()) return false;
            return *it < hi;
        }

        int m = (b + e) >> 1, l = p << 1, r = l | 1;

        if (x < m) if (contains(l, b, m, x, y, lo, hi)) return true;
        if (m < y) if (contains(r, m, e, x, y, lo, hi)) return true;

        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    int M = min(n, m);

    vector<segment_tree> sizes(M + 1, segment_tree(n));

    vector<string> board(n);

    vector<vector<vector<int>>> acc(4, vector<vector<int>>(n + 1, vector<int>(m + 1)));

    string color = "RGYB";

    for (int i = 0; i < n; ++i) {
        cin >> board[i];

        for (int j = 0; j < m; ++j) {
            int ix = color.find(board[i][j]);
            // cout << ix << endl;
            acc[ix][i + 1][j + 1]++;

            for (int k = 0; k < 4; ++k) {
                acc[k][i + 1][j + 1] += acc[k][i + 1][j] + acc[k][i][j + 1] - acc[k][i][j];
            }
        }
    }

    int HI = 0;

    auto is_full = [&](int x1, int y1, int x2, int y2, int k) {
        // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << k << endl;
        if (x1 < 0) return false;
        if (y1 < 0) return false;
        if (x2 >= n) return false;
        if (y2 >= m) return false;

        auto tot = acc[k][x2 + 1][y2 + 1] - acc[k][x2 + 1][y1] - acc[k][x1][y2 + 1] + acc[k][x1][y1];
        return tot == (x2 - x1 + 1) * (y2 - y1 + 1);
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // cout << endl << " start: " << i << " " << j << endl;

            bool ok = true;

            for (int k = 1; ok; ++k) {
                int x1 = i - k + 1, y1 = j - k + 1;

                for (int dx = 0, c = 0; dx < 2 && ok; ++dx) {
                    for (int dy = 0; dy < 2 && ok; ++dy) {
                        if (!is_full(x1 + dx * k, y1 + dy * k, x1 + k - 1 + dx * k, y1 + k - 1 + dy * k, c++))
                            ok = false;
                    }
                }

                if (ok) {
                    // cout << "ok: " << i << " " << j << " " << k << endl;

                    sizes[k].insert(1, 0, n, i, j);
                    HI = max(HI, k);
                }
            }
        }
    }

    // exit(0);

    while (q-->0) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int lo = 0, hi = HI + 1;

        while (lo + 1 < hi) {
            int m = (lo + hi) >> 1;

            int nx1 = x1 + m - 1;
            int ny1 = y1 + m - 1;
            int nx2 = x2 - m;
            int ny2 = y2 - m;

            bool ok = true;

            if (nx1 > nx2) ok = false;
            if (ny1 > ny2) ok = false;

            if (!ok) {
                hi = m;
                continue;
            }

            assert(m <= M);

            if (sizes[m].contains(1, 0, n, nx1, nx2 + 1, ny1, ny2 + 1)) {
                lo = m;
            } else {
                hi = m;
            }
        }

        cout << lo * 4 * lo << endl;
    }

    return 0;
}