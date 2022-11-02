#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int maxn = 100100;

int n;
vector<int> adj[maxn];
int sub[maxn];
ld ans[maxn];

void dfs0(int v) {
    sub[v] = 1;
    for (int i : adj[v]) {
        dfs0(i);
        sub[v] += sub[i];
    }
}

void dfs(int v, ld x = 0) {
    ans[v] = x + 1;
    for (int i : adj[v])
        dfs(i, x + 1 + ld(sub[v] - 1 - sub[i]) / 2);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }

    dfs0(1);
    dfs(1);

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}