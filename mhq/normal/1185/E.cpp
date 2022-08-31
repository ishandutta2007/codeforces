#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
const int maxN = 2005;
vector < int > need[maxN][maxN];
int n, m;
char tp[maxN][maxN];
vector < pair < int, int > > cells[40];
int cnt[40];
const int ROW = 0;
const int COL = 1;
int ti[40], l[40], r[40];
int val[40];
bool go(int v) {
    int mxr = -1;
    int mnr = -1;
    int mxcl = -1;
    int mncl = -1;
    for (auto& t : cells[v]) {
        if (mxr == -1 || mxr < t.first) mxr = t.first;
        if (mnr == -1 || mnr > t.first) mnr = t.first;
        if (mxcl == -1 || mxcl < t.second) mxcl = t.second;
        if (mncl == -1 || mncl > t.second) mncl = t.second;
    }
    if (mxr != mnr && mxcl != mncl) return false;
    if (mxr == mnr) {
        ti[v] = ROW;
        l[v] = mncl;
        r[v] = mxcl;
        val[v] = mnr;
        cnt[v] = mxcl - mncl + 1;
        for (int j = mncl; j <= mxcl; j++) {
            need[mxr][j].push_back(v);
        }
    }
    else {
        ti[v] = COL;
        l[v] = mnr;
        r[v] = mxr;
        cnt[v] = mxr - mnr + 1;
        val[v] = mxcl;
        for (int j = mnr; j <= mxr; j++) {
            need[j][mncl].push_back(v);
        }
    }
    return true;
}
bool used[40];
bool was[maxN][maxN];
char ntp[maxN][maxN];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < 26; i++) {
        cells[i].clear();
        cnt[i] = 0;
        ti[i] = -1;
        used[i] = false;
    }
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            need[i][j].clear();
            ntp[i][j] = '.';
            cin >> tp[i][j];
            was[i][j] = false;
            mx = max(mx, tp[i][j] - 'a');
            if (tp[i][j] != '.') {
                cells[tp[i][j] - 'a'].emplace_back(i, j);
            }
        }
    }
    if (mx == -1) {
        cout << "YES" << '\n' << 0 << '\n';
        return;
    }
    for (int k = 0; k < 26; k++) {
        if (!cells[k].empty()) {
            if (!go(k)) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    for (int i = 0; i <= mx; i++) {
        if (ti[i] == -1) {
            ti[i] = ti[mx];
            val[i] = val[mx];
            l[i] = l[mx];
            r[i] = r[mx];
        }
        if (ti[i] == ROW) {
            for (int j = l[i]; j <= r[i]; j++) {
                ntp[val[i]][j] = 'a' + i;
            }
        }
        else {
            for (int j = l[i]; j <= r[i]; j++) {
                ntp[j][val[i]] = 'a' + i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ntp[i][j] != tp[i][j]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    cout << mx + 1 << '\n';
    for (int v = 0; v <= mx; v++) {
        if (ti[v] == ROW) {
            cout << val[v] << " " << l[v] << " " << val[v] << " " << r[v] << '\n';
        }
        else {
            cout << l[v] << " " << val[v] << " " << r[v] << " " << val[v] << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}