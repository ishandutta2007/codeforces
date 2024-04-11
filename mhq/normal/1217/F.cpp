#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
set < pair < int, int > > ed;
const int maxN = 2 * (int)1e5 + 100;
const int BLOCK = 1500;
int x[maxN], y[maxN], tp[maxN];
int cmp[maxN];
vector < int > g[maxN];
int sz = 0;

void dfs(int v) {
    cmp[v] = sz;
    for (int to : g[v]) {
        if (cmp[to] == 0) {
            dfs(to);
        }
    }
}

vector < int > cmp_edges[maxN];
bool vis[maxN];
vector < int > all;
void go(int v) {
    vis[v] = true;
    all.push_back(v);
    for (int to : cmp_edges[v]) {
        if (vis[to]) continue;
        vis[to] = true;
        go(to);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> tp[i] >> x[i] >> y[i];
        if (x[i] > y[i]) swap(x[i], y[i]);
    }
    int lst = 0;
    string s;
    for (int i = 0; i < m; i += BLOCK) {
        int l = i;
        int r = min(i + BLOCK - 1, m - 1);
        set < pair < int, int > > survive = ed;
        for (int j = l; j <= r; j++) {
            int x1 = (x[j] - 1) % n + 1; int y1 = (y[j] - 1) % n + 1;
            if (x1 > y1) swap(x1, y1);
            if (survive.find(make_pair(x1, y1)) != survive.end()) survive.erase(make_pair(x1, y1));
            int x2 = x[i] % n + 1; int y2 = y[i] % n + 1;
            if (x2 > y2) swap(x2, y2);
            if (survive.find(make_pair(x2, y2)) != survive.end()) survive.erase(make_pair(x2, y2));
        }
        for (int j = 1; j <= n; j++) {
            g[j].clear();
            cmp[j] = 0;
        }
        for (auto it : survive) {
            g[it.first].push_back(it.second);
            g[it.second].push_back(it.first);
        }
        sz = 1;
        for (int j = 1; j <= n; j++) {
            if (cmp[j] == 0) {
                cmp[j] = sz;
                dfs(j);
                sz++;
            }
        }
        for (int j = 1; j < sz; j++) {
            cmp_edges[j].clear();
        }
        for (auto it : ed) {
            if (survive.find(it) == survive.end()) {
                int x = cmp[it.first];
                int y = cmp[it.second];
                if (x == y) continue;
                cmp_edges[x].push_back(y);
                cmp_edges[y].push_back(x);
            }
        }
        for (int j = l; j <= r; j++) {
            if (tp[j] == 1) {
                int x1 = (x[j] + lst - 1) % n + 1; int y1 = (y[j] + lst - 1) % n + 1;
                if (x1 > y1) swap(x1, y1);
                if (ed.find(make_pair(x1, y1)) != ed.end()) {
                    ed.erase(make_pair(x1, y1));
                    x1 = cmp[x1];
                    y1 = cmp[y1];
                    if (x1 == y1) continue;
                    cmp_edges[x1].erase(find(cmp_edges[x1].begin(), cmp_edges[x1].end(), y1));
                    cmp_edges[y1].erase(find(cmp_edges[y1].begin(), cmp_edges[y1].end(), x1));
                }
                else {
                    ed.insert(make_pair(x1, y1));
                    x1 = cmp[x1];
                    y1 = cmp[y1];
                    if (x1 == y1) continue;
                    cmp_edges[x1].push_back(y1);
                    cmp_edges[y1].push_back(x1);
                }
            }
            else {
                int x1 = (x[j] + lst - 1) % n + 1; int y1 = (y[j] + lst - 1) % n + 1;
                if (x1 > y1) swap(x1, y1);
                x1 = cmp[x1];
                y1 = cmp[y1];
                if (x1 == y1) {
                    lst = 1;
                }
                else {
                    go(x1);
                    lst = (int)vis[y1];
                    for (int v : all) vis[v] = false;
                    all.clear();
                }
                s += (char)(lst + '0');
            }
        }
    }
    cout << s << '\n';

    return 0;
}