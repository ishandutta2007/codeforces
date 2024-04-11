#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2005;
int p[maxN], c[maxN];
vector < int > g[maxN];
int sz[maxN];
int a[maxN];
vector < pair < int, int > > vals[maxN];
void dfs(int v) {
    sz[v] = 1;
    for (int to : g[v]) {
        dfs(to);
        sz[v] += sz[to];
        for (auto it : vals[to]) {
            vals[v].push_back(it);
        }
    }
    c[v]++;
    if (c[v] > sz[v]) {
        cout << "NO";
        exit(0);
    }
    sort(vals[v].begin(), vals[v].end());
    if (c[v] - 1 != vals[v].size()) {
        a[v] = vals[v][c[v] - 1].first + 1;
        for (int j = c[v] - 1; j < vals[v].size(); j++) {
            vals[v][j].first += 2;
            a[vals[v][j].second] += 2;
        }
    }
    else {
        if (vals[v].empty()) a[v] = 1;
        else a[v] = vals[v].back().first + 1;
    }
    vals[v].emplace_back(a[v], v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //n = 2000;
    int root = -1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        //p[i] = i - 1;
        //c[i] = 0;
        if (p[i] == 0) {
            root = i;
        }
        else {
            g[p[i]].push_back(i);
        }
    }
    assert(root != -1);
    dfs(root);
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}