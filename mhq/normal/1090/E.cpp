#include <bits/stdc++.h>
using namespace std;
int k;
string s[8];
int good[8][8];
int used[8][8];
pair<int, int> q[100];
pair<int, int> nxt[8][8];
vector<string> ans;
const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

void go(int sx, int sy) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            used[i][j] = 0;
        }
    }
    int l = 1;
    int sz = 1;
    q[1] = make_pair(sx, sy);
    used[sx][sy] = 1;
    while (l <= sz) {
        auto cur = q[l];
        int x = cur.first;
        int y = cur.second;
        if (s[cur.first][cur.second] == 'k' && !good[cur.first][cur.second]) {
            vector<pair<int, int> > tmp;
            while (x != sx || y != sy) {
                tmp.emplace_back(make_pair(x, y));
                auto to = nxt[x][y];
                x = to.first;
                y = to.second;
            }
            tmp.emplace_back(make_pair(sx, sy));
            reverse(tmp.begin(), tmp.end());
            vector<pair<int, int> > cells;
            for (auto cur: tmp) {
                cells.push_back(cur);
                if (s[cur.first][cur.second] == 'k') {
                    reverse(cells.begin(), cells.end());
                    for (int i = 0; i + 1 < cells.size(); i++) {
                        swap(s[cells[i].first][cells[i].second], s[cells[i + 1].first][cells[i + 1].second]);
                        string sh;
                        sh += (char)('a' + cells[i].second);
                        sh += (char)('1' + cells[i].first);
                        sh += '-';
                        sh += (char)('a' + cells[i + 1].second);
                        sh += (char)('1' + cells[i + 1].first);
                        ans.push_back(sh);
                    }
                    cells.clear();
                    cells.push_back(make_pair(cur.first, cur.second));
                    sx = cur.first;
                    sy = cur.second;
                }
            }
            return;
        }
        for (int i = 0; i < 8; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8) {
                continue;
            }
            if (used[tx][ty]) {
                continue;
            }
            sz++;
            q[sz] = make_pair(tx, ty);
            used[tx][ty] = 1;
            nxt[tx][ty] = make_pair(x, y);
        }
        l++;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> k;
    for (int i = 0; i < 8; i++) {
        s[i] = "........";
    }
    for (int i = 1; i <= k; i++) {
        string w;
        cin >> w;
        int y = w[0] - 'a';
        int x = w[1] - '1';
        s[x][y] = 'k';
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] != 'k') {
                go(i, j);
            }
            good[i][j] = 1;
            cnt++;
            if (cnt == k) break;
        }
        if (cnt == k) break;
    }
    cout << ans.size() << "\n";
    for (auto p: ans) {
        cout << p << "\n";
    }
    return 0;
}