#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 205;

int n, t, ans[N][N];

int ask(int u, int v) {
    if (ans[u][v] != 0) {
        return ans[u][v];
    }
    char c;
    cout << "? " << u << " " << v << endl;
    cin >> c;
    if (c == '<') {
        ans[u][v] = -1;
        ans[v][u] = 1;
    } else {
        ans[u][v] = 1;
        ans[v][u] = -1;
    }
    return ans[u][v];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            ans[i][j] = 0;
        }
    }
    vector<pair<int, int>> ve;
    for (int i = 1; i <= n; i++) {
        int u = i, v = i + n;
        if (ask(u, v) == 1) {
            swap(u, v);
        }
        ve.push_back({u, v});
    }
    sort(ve.begin(), ve.end(), [](const pair<int, int> &u, const pair<int, int> &v) {
        return ask(u.fi, v.fi) == -1;
    });
    vector<int> cur;
    for (int i = 0; i < n - 1; i++) {
        cur.push_back(ve[i].fi);
        cur.push_back(ve[i].se);
    }
    sort(cur.begin(), cur.end(), [](const int &u, const int &v) {
        return ask(u, v) == -1;
    });
    ask(cur[cur.size() / 2], ve.back().fi);
    cout << "!" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}