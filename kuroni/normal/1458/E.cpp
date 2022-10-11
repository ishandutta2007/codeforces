#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 100005;

int n, m, x, y;
bool ans[N];
int col = 0, row = 0;
set<int> chk, cur;
map<int, vector<int>> ori;
map<int, vector<pair<int, int>>> que;

int compute(int cur, int st) {
    while (!chk.empty() && cur + st >= *chk.begin()) {
        st -= *chk.begin() - cur;
        cur = *chk.begin() + 1;
        chk.erase(chk.begin());
    }
    return cur + st;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        ori[x].push_back(y);
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        que[x].push_back({y, i});
    }
    while (!que.empty()) {
        int nr = que.begin()->fi;
        if (!ori.empty()) {
            nr = min(nr, ori.begin()->fi);
        }
        cur.clear();
        bool ins = true, eq = false;
        col = compute(col, nr - row);
        if (!ori.empty() && nr == ori.begin()->fi) {
            for (int v : ori.begin()->se) {
                cur.insert(v);
                if (v > col) {
                    chk.insert(v);
                } else if (v < col) {
                    ins = false;
                } else {
                    eq = true;
                }
            }
            ori.erase(ori.begin());
        }
        if (ins) {
            cur.insert(col);
            row = nr;
        } else {
            col += eq;
            row = nr + 1;
        }
        if (nr == que.begin()->fi) {
            for (auto [y, ind] : que.begin()->se) {
                ans[ind] = cur.count(y);
            }
            que.erase(que.begin());
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << (ans[i] ? "LOSE\n" : "WIN\n");
    }
}