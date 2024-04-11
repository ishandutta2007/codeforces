#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, root;
vector<int> g[N];
int depth[N];

void dfs(int v, int par = -1) {
    depth[v] = par == -1 ? 0 : depth[par] + 1;
    for (int to : g[v]) {
        if (to != par)
            dfs(to, v);
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int v = 1; v <= n; v++) {
        if ((int) g[v].size() > 1) {
            root = v;
            break;
        }
    }

    dfs(root);

    int used[2] = {0, 0};

    for (int v = 1; v <= n; v++) {
        if ((int) g[v].size() == 1)
            used[depth[v] % 2] = 1;
    }

    if (used[0] && used[1]) {
        cout << "3\n";
    } else {
        cout << "1\n";
    }

    int mx = 0;
    for (int v = 1; v <= n; v++) {
        int leafs = 0;
        for (int to : g[v]) {
            if ((int) g[to].size() == 1) {
                leafs++;
            }
        }
        mx += (leafs > 0);
        if (v == root) {
            mx += (int) g[v].size() - leafs;
        } else {
            mx += (int) g[v].size() - leafs - 1;
        }
    }

    cout << mx << "\n";

    return 0;
}