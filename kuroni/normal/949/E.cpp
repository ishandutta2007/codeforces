#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int INF = 1E9 + 7;

int n, cnt = 0;
vector<int> tr, co, ve;

pair<int, int> solve(int u, vector<int> ve) {
    int cur = cnt++;
    tr.push_back(0); co.push_back(0);
    if (ve.size() == 1) {
        tr[cur] = -1;
        return {0, cur};
    } else if (u > 20) {
        tr[cur] = -1;
        return {INF, cur};
    }
    int chk = false;
    for (int &v : ve) {
        if (v & 1) {
            chk = true;
            break;
        }
    }
    if (!chk) {
        for (int &v : ve) {
            v /= 2;
        }
        pair<int, int> ret = solve(u + 1, ve);
        tr[cur] = ret.se;
        return {ret.fi, cur};
    } else {
        vector<int> mi, pl;
        for (int &v : ve) {
            if (v & 1) {
                mi.push_back((v + 1) / 2);
                pl.push_back((v - 1) / 2);
            } else {
                mi.push_back(v / 2);
                pl.push_back(v / 2);
            }
        }
        mi.erase(unique(mi.begin(), mi.end()), mi.end());
        pl.erase(unique(pl.begin(), pl.end()), pl.end());
        pair<int, int> le = solve(u + 1, mi), ri = solve(u + 1, pl);
        if (le < ri) {
            tr[cur] = le.se;
            co[cur] = -1;
            return {le.fi + 1, cur};
        } else {
            tr[cur] = ri.se;
            co[cur] = 1;
            return {ri.fi + 1, cur};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ve = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    cout << solve(0, ve).fi << '\n';
    for (int cur = 0, i = 0; i <= 20 && cur != -1; i++, cur = tr[cur]) {
        if (co[cur] != 0) {
            cout << co[cur] * (1 << i) << " ";
        }
    }
}