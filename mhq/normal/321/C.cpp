#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int n;
int clr[maxN];
bool used[maxN];
vector < int > g[maxN];
int sz[maxN];
int big[maxN];
void dfs(int v, int p) {
    sz[v] = 1;
    big[v] = -1;
    for (int to : g[v]) {
        if (used[to]) continue;
        if (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        if (big[v] == -1 || sz[big[v]] < sz[to]) {
            big[v] = to;
        }
    }
}
void build_cd(int root, int layer) {
    dfs(root, -1);
    int n = sz[root];
    int cur_v = root;
    while (big[cur_v] != -1 && sz[big[cur_v]] > n / 2) {
        cur_v = big[cur_v];
    }
    clr[cur_v] = layer;
    used[cur_v] = true;
    for (int to : g[cur_v]) {
        if (used[to]) continue;
        build_cd(to, layer + 1);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    build_cd(1, 1);
    for (int i = 1; i <= n; i++) {
        cout << (char)(clr[i] - 1 + 'A') << " ";
    }
    return 0;
}