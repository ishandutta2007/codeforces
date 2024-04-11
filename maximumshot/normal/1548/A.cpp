#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<set<int>> g(n + 1);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    auto check = [&](int v) -> bool {
        return (g[v].empty() || *(--g[v].end()) < v);
    };

    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (check(i))
            cur++;
    }

    int q;
    cin >> q;

    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        if (t == 3) {
            cout << cur << "\n";
        } else {
            int u, v;
            cin >> u >> v;
            cur -= (check(u) + check(v));
            if (t == 1) {
                g[u].insert(v);
                g[v].insert(u);
            } else {
                g[u].erase(v);
                g[v].erase(u);
            }
            cur += (check(u) + check(v));
        }
    }

    return 0;
}