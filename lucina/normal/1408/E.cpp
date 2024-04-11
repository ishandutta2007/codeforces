#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;
int n, m;
int a[nax];
int b[nax];
struct Edge {
    int u, v;
    int64_t w;
    bool operator < (const Edge &other) const {
        return w > other.w;
    }
    Edge(int u, int v, int64_t w) : u(u), v(v), w(w) {}
};
int par[nax];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

vector <Edge> edges;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> m >> n;

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> a[i];
    }

    for (int i = 1 ; i <= n;  ++ i) {
        cin >> b[i];
    }

    int64_t all = 0;  
    edges.reserve(1 << 18);

    for (int i = 1 ; i <= m ; ++ i) {
        int s;
        cin >> s;
        for (int v = 1 ; v <= s ; ++ v) {
            int j;
            cin >> j;
            int cost  = a[i] + b[j];
            edges.emplace_back(i, m + j, cost);
            all += cost;
        }
    }

    iota(par + 1, par + 1 + n + m, 1);
    sort(edges.begin(), edges.end());

    int64_t mst = all;

    for (auto [u, v, w] : edges) {
        u = find(u);
        v = find(v);
        if (u == v) continue;
        mst -= w;
        par[u] = v;
    }
    cout << mst << '\n';
}
/*
    Good Luck
        -Lucina
*/