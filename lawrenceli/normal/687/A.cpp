#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;

int n, m;
vector<int> adj[maxn];

vector<int> nums[2];

int col[maxn];

void dfs(int v, int c) {
    if (col[v] != -1) {
        if (col[v] != c) {
            cout << "-1\n";
            exit(0);
        }
        return;
    }

    col[v] = c;
    nums[c].push_back(v);
    for (int i : adj[v])
        dfs(i, !c);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; i++)
        if (col[i] == -1)
            dfs(i, 0);

    for (int i = 0; i < 2; i++) {
        cout << nums[i].size() << '\n';
        for (int j : nums[i]) cout << j << ' ';
        cout << '\n';
    }
}