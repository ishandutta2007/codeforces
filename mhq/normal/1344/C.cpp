#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 2e5 + 10;
vector < int > g[maxN];
int n, m;
bool used[maxN];
vector < int > ord;
int id[maxN];
void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) continue;
        dfs(to);
    }
    ord.emplace_back(v);
}
int mn[maxN];
vector < int > gr[maxN];
int mn2[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        gr[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        id[ord[i]] = i;
    }
    for (int v : ord)  {
        for (int u : g[v]) {
            if (id[u] > id[v]) {
                cout << -1;
                return 0;
            }
        }
    }
    for (int v : ord) {
        mn[v] = v;
        for (int u : g[v]) {
            mn[v] = min(mn[v], mn[u]);
        }
    }
    for (int i = ord.size() - 1; i >= 0; i--) {
        mn2[ord[i]] = ord[i];
        for (int p : gr[ord[i]]) {
            mn2[ord[i]] = min(mn2[ord[i]], mn2[p]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mn[i] >= i && mn2[i] >= i) cnt++;
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (mn[i] >= i && mn2[i] >= i) cout << "A";
        else cout << "E";
    }
    return 0;
}