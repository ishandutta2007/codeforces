#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int a[nax];
vector <int> g[nax];
int sum;
int f[nax];
int par[nax];
void dfs(int node, int parent) {
    f[node] = a[node];
    par[node] = parent;
    for (int to : g[node]) {
        if (to == parent) continue;
        dfs(to, node);
        f[node] ^= f[to];
    }
}

bool solve() {
    cin >> n >> k;
    sum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        sum ^= a[i];
    }
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (k == 2) {
        return sum == 0;
    }
    if (sum == 0) return true;
    dfs(1, 0);

    int cnt = count(f + 2, f + 2 + n, sum);
    if (cnt > 1) return true;
    if (cnt == 1) {
        int where = find(f + 2, f + 2 + n, sum) - f;
        while (par[where]) {
            where = par[where];
            if (f[where] == 0) return true;
        }
    }
    return false;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}
/*
    Well, such a long time from last div.2 round
*/