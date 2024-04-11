#include <bits/stdc++.h>
using namespace std;
const int maxN = 5 * (int)1e5 + 10;
int n, m;
vector < int > g[maxN];
vector < int > *vin[maxN];
vector < pair < int, int > > q[maxN];
bool ans[maxN];
int h[maxN];
int sz[maxN];
int col[maxN];
int cnt[maxN][30];
void st(int v) {
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        st(to);
        sz[v] += sz[to];
    }
}
void dfs(int v, bool keep) {
    int mx = -1, big = -1;
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (sz[u] > mx) {
            mx = sz[u];
            big = u;
        }
    }
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (u != big) dfs(u, 0);
    }
    if (big != -1) {
        dfs(big, 1);
        vin[v] = vin[big];
    }
    else vin[v] = new vector <  int > ();
    vin[v] -> push_back(v);
    cnt[h[v]][col[v]]++;
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (u != big) {
            for (int j = 0; j < (*vin[u]).size(); j++) {
                int to = (*vin[u])[j];
                cnt[h[to]][col[to]]++;
                vin[v] -> push_back(to);
            }
        }
    }
    for (int j = 0; j < q[v].size(); j++) {
        int he = q[v][j].first, ind = q[v][j].second;
        int odd = 0;
        for (int k = 0; k < 26; k++) {
            if (cnt[he][k] % 2 == 1) odd++;
        }
        if (odd <= 1) ans[ind] = true;
        else ans[ind] = false;
    }
    if (keep == 0) {
        for (int i = 0; i < (*vin[v]).size(); i++) {
            int to = (*vin[v])[i];
            cnt[h[to]][col[to]]--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("log.in", "r", stdin);
    //freopen("log.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    h[1] = 1;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
        h[i] = h[x] + 1;
    }
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        col[i] = c - 'a';
    }
    for (int i = 1; i <= m; i++) {
        int v, h;
        cin >> v >> h;
        q[v].push_back(make_pair(h, i));
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        if (ans[i]) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}