#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, m;
vector<string> a;
vector<int> c;
vector<vector<int>> id, nxid;
int cc;
vector<vector<int>> g;
vector<int> scc, low, num;
int cnt, cntscc;
stack<int> st;

void tryadd(int u, int v) {
    if (u == 0 || v == 0 || u == v) return;
    g[u].push_back(v);
}

bool in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (auto v: g[u]) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        ++cntscc;
        int v;
        do {
            v = st.top();
            st.pop();
            scc[v] = cntscc;
            num[v] = low[v] = inf;
        } while (v != u);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.assign(n, "");
    c.assign(m, 0);
    id.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> c[i];

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (a[i][j] == '#' && !id[i][j]) {
        id[i][j] = ++cc;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int t = 0; t < 4; ++t) {
                int nx = x + dx[t], ny = y + dy[t];
                if (!in(nx, ny) || a[nx][ny] == '.' || id[nx][ny]) continue;
                id[nx][ny] = cc;
                q.push({nx, ny});
            }
        }
    }

    nxid = id;
    for (int i = n - 2; i >= 0; --i) for (int j = 0; j < m; ++j) if (nxid[i][j] == 0) nxid[i][j] = nxid[i+1][j];

    g.assign(cc + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) for (int j = 0; j < m; ++j) {
        if (!id[i][j]) continue;
        int u = id[i][j];
        if (j > 0) tryadd(u, nxid[i+1][j-1]);
        tryadd(u, nxid[i+1][j]);
        if (j < m - 1) tryadd(u, nxid[i+1][j+1]);
    }

    scc.assign(cc + 1, 0);
    low.assign(cc + 1, 0);
    num.assign(cc + 1, 0);
    for (int i = 1; i <= cc; ++i) if (!num[i]) dfs(i);

    vector<bool> good(cntscc + 1, true);
    for (int i = 1; i <= cc; ++i) {
        for (auto v: g[i]) if (scc[i] != scc[v]) good[scc[v]] = false;
    }
    int ans = 0;
    for (int i = 1; i <= cntscc; ++i) ans += good[i];
    cout << ans << endl;
    return 0;
}