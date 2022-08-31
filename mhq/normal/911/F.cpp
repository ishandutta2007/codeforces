#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
vector < int > g[maxN];
int h[maxN];
int h1[maxN];
int up[maxN][20];
bool used[maxN];
bool used1[maxN];
int n;
int dist[maxN];
int deg[maxN];
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            h[to] = h[v] + 1;
            dfs(to);
        }
    }
}
void dfs1(int v) {
    used1[v] = true;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!used1[to]) {
                h1[to] = h1[v] + 1;
                up[to][0] = v;
                dfs1(to);
            }
    }
}
int lca(int x, int y) {
    if (h1[x] < h1[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (h1[x] - (1 << i) >= h1[y]) x = up[x][i];
    }
    for (int i = 19; i >= 0; i--) {
        if (up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
    }
    return up[x][0];
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= (n - 1); i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    dfs(1);
    int mx = -1;
    int ind = -1;
    for (int i = 1; i <= n; i++) {
        if (h[i] > mx) {
            mx = h[i];
            ind = i;
        }
    }
    //queue < int > q;
    dfs1(ind);
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    int mx1 = -1;
    int ind1 = -1;
    for (int i = 1; i <= n; i++) {
        if (h1[i] > mx1) {
            mx1 = h1[i];
            ind1 = i;
        }
    }
    //cout << mx1 << endl;
    //cout << h1[3] << " " << h1[5] << endl;
    int a = ind;
    int b = ind1;
    //cout << a << b << '\n'
    queue < int > leaf;
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b) continue;
        if (deg[i] == 1) leaf.push(i);
    }
    long long ans1 = 0;
    vector < pair < int, pair < int, int > > > ans;
    //cout << a << b << endl;
    while (!leaf.empty()) {
        int v = leaf.front();
        leaf.pop();
        int lca1 = lca(a, v);
        int lca2 = lca(b, v);
        if (h1[v] + h1[a] - 2 * h1[lca1] > h1[v] + h1[b] - 2 * h1[lca2]) {
            //cout << a << " " << v << " " << v;
            ans.push_back(make_pair(a, make_pair(v, v)));
        }
        else {
            //cout << b << " " << v << " " << v;
            ans.push_back(make_pair(b, make_pair(v, v)));
        }
        ans1 += max(h1[v] + h1[a] - 2 * h1[lca1], h1[v] + h1[b] - 2 * h1[lca2]);
        deg[v]--;
        deg[up[v][0]]--;
        if (deg[up[v][0]] == 1) leaf.push(up[v][0]);
    }
    ans1 += (1LL * h1[b] * (h1[b] + 1)) / 2;
    cout << ans1 << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << '\n';
    }
    //cout << "HERE" << endl;
    int t = h1[b];
    for (int i = 0; i < t; i++) {
        cout << a << " " << b << " " << b << '\n';
        b = up[b][0];
    }
}