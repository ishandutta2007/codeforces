#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int n, m, match[505], vis[505], deg[505], num[505], lev[505], val[505][505], b[505];
vector<int> g[505];
bitset<505> a[505];

bool dfs(int v) {
    if (vis[v]) return false; vis[v] = true;
    for (int x : g[v]) {
        if (match[x] == -1 || dfs(match[x])) {
            match[x] = v;
            return true;
        }
    }
    return false;
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string S; cin >> S;
        for (int j = 0; j < m; j++) {
            a[j][i] = (S[j] == '1');
        }
    }
    fill(b, b + m, INF);
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        if (a[i] == a[j]) {
            int k = min(i, j);
            b[i] = min(b[i], k);
            b[j] = min(b[j], k);
            continue;
        }
    }
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        if (b[i] == i && b[j] == j && i != j && (a[i] & a[j]) == a[j]) {
            g[i].push_back(j);
        }
    }
    int ans = 0, cnt = 0;
    fill(match, match + m, -1);
    for (int i = 0; i < m; i++) if (b[i] == i) {
        ans += dfs(i);
        ++cnt;
        fill(vis, vis + m, 0);
    }
    int k = cnt - ans;
    for (int i = 0; i < m; i++) if (b[i] == i) {
        if (match[i] != -1) deg[match[i]]++;
    }
    int s = 0;
    for (int i = 0; i < m; i++) if (b[i] == i && !deg[i]) {
        int x = i;
        vector<int> v;
        while (x != -1) {
            v.push_back(x);
            x = match[x];
        }
        ++s;
        for (int x : v) num[x] = s;
        bitset<505> t;
        int c = 0;
        for (int x : v) {
            a[x] ^= t; lev[x] = INF - c;
            for (int j = 0; j < n; j++) if (a[x][j]) {
                val[j][s] = INF - c;
            }
            ++c;
            t |= a[x];
        }
    }
    cout << k << '\n';
    for (int i = 0; i < m; i++) cout << num[b[i]] << ' '; cout << '\n';
    for (int i = 0; i < m; i++) cout << lev[b[i]] + 1 << ' '; cout << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) cout << val[i][j] + 1 << ' ';
        cout << '\n';
    }
}