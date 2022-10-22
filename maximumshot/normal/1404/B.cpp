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

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    vector<vector<int>> g(n + 1);
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::function<vector<int>(int)> fnd_dist = [&](int s) -> vector<int> {
        vector<int> dist(n + 1, inf);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        return dist;
    };
    vector<int> dist_a = fnd_dist(a), dist_b = fnd_dist(b);
    int leaf = -1;
    for (int i = 1; i <= n; i++) {
        if (leaf == -1 || dist_a[leaf] < dist_a[i])
            leaf = i;
    }
    vector<int> dist_leaf = fnd_dist(leaf);
    int D = *max_element(dist_leaf.begin() + 1, dist_leaf.end());
    if (dist_a[b] > da && db >= 2 * da + 1 && D > 2 * da) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    for (int ti = 1; ti <= tt; ti++)
        solve();

    return 0;
}