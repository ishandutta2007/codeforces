#include <bits/stdc++.h>

using namespace std;

const int maxn = 100500;

vector<pair<int, int>> edge[maxn];

int Dfs(int v, int anc = -1) {
    int max_path = 0;
    for (const auto& [to, c] : edge[v]) {
        if (to == anc) {
            continue;
        }
        int x = Dfs(to, v);
        max_path = max(max_path, x + c);
    }
    return max_path;
}

int main() {
    srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int total = 0;
    for (int i = 1; i < n; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        total += c;
        edge[u].emplace_back(v, c);
        edge[v].emplace_back(u, c);
    }

    cout << (2LL * total - Dfs(1)) << endl;
}