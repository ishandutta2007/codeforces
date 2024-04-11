#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct DSU {
    int n; // [1, n]
    vector<int> p;

    DSU(int nn) {
        n = nn;
        p.resize(n + 1);
        for (int i = 1; i <= n; i++)
            p[i] = i;
    }

    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        p[y] = x;
        return true;
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int m, n;
    cin >> m >> n;

    vector<int> a(m + 1), b(n + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int j = 1; j <= n; j++)
        cin >> b[j];

    vector<tuple<int, int, int>> edges;
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int it = 0; it < k; it++) {
            int j;
            cin >> j;
            res += a[i] + b[j];
            edges.emplace_back(a[i] + b[j], i, m + j);
        }
    }

    sort(edges.rbegin(), edges.rend());
    DSU dsu(n + m);

    for (auto [w, u, v] : edges) {
        if (dsu.merge(u, v))
            res -= (a[u] + b[v - m]);
    }

    cout << res << "\n";

    return 0;
}