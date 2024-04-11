#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1000;
vector<int> ed[N];
int used[N];
int calced[N][N];
int deleted[N], d[N][N], q[N], t, up[N], tin[N], good[N];
void dfs(int v, int par) {
    used[v] = 1;
    t++;
    tin[v] = t;
    up[v] = t;
    int k = 0;
    bool ok = 0;
    for (auto to: ed[v]) {
        if (deleted[to]) continue;
        if (!used[to]) {
            dfs(to, v);
            if (up[to] >= tin[v]) {
                ok = 1;
            }
            k++;
            up[v] = min(up[v], up[to]);
        }
        else {
            if (to != par) up[v] = min(up[v], tin[to]);
        }
    }
    if (par == 0) {
        if (k == 1) ok = 0;
        else ok = 1;
    }
    if (ok) good[v] = 1;
}
void build(int v, int par) {
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
        good[i] = 0;
    }
    t = 0;
    dfs(v, 0);
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        if (used[i] == 1) {
            tmp.push_back(i);
        }
    }
    pair<int, int> mn = make_pair(1, n * n + 20);
    int centroid = 0;
    calced[v][par] = 0;
    if (calced[v][par] != 0) {
        centroid = calced[v][par];
    }
    else {
        for (auto i: tmp) {
            for (int j: tmp) {
                d[i][j] = n + 1;
            }
            d[i][i] = 0;
            int l = 1;
            int sz = 1;
            q[1] = i;
            while (l <= sz) {
                int vv = q[l];
                for (auto to: ed[vv]) {
                    if (deleted[to] == 1) continue;
                    if (d[i][to] > d[i][vv] + 1) {
                        d[i][to] = d[i][vv] + 1;
                        sz++;
                        q[sz] = to;
                    }
                }
                l++;
            }
        }
        for (int i: tmp) {
            int mx = 0;
            for (auto to: ed[i]) {
                if (deleted[to] == 1) continue;
                int cnt = 0;
                for (auto j: tmp) {
                    if (d[i][j] > d[to][j]) {
                        cnt++;
                    }
                }
                mx = max(mx, cnt);
            }
            if (make_pair(0, mx) < mn) {
                centroid = i;
                mn = make_pair(0, mx);
            }
        }
        calced[v][par] = centroid;
    }
    cout << centroid << endl;
    string s;
    cin >> s;
    if (s == "FOUND") {
        return;
    }
    int to;
    cin >> to;
    deleted[centroid] = 1;
    for (int j: tmp) {
        if (d[centroid][j] <= d[to][j]) deleted[j] = 1;
    }
    build(to, centroid);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        int prev = 0;
        for (int j = 1; j <= k; j++) {
            int v;
            cin >> v;
            if (prev != 0) {
                ed[prev].push_back(v);
                ed[v].push_back(prev);
            }
            prev = v;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            deleted[j] = 0;
        }
        build(1, 0);
    }
    return 0;
}