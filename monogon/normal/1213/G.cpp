
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, q, u, v, w;
int par[N];
ll sz[N];
vector<tuple<int, int, int> > edges;
ll ans[N];

int find(int x) {
    return par[x] == -1 ? x : par[x] = find(par[x]);
}
void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(sz[x] < sz[y]) {
        swap(x, y);
    }
    sz[x] += sz[y];
    par[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    fill(par, par + n, -1);
    fill(sz, sz + n, 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    int j = 0;

    ll tot = 0;
    for(int i = 0; i < N; i++) {
        while(j < edges.size() && get<0>(edges[j]) <= i) {
            u = find(get<1>(edges[j]));
            v = find(get<2>(edges[j]));
            if(u != v) {
                tot += sz[u] * sz[v];
                join(u, v);
            }
            j++;
        }
        ans[i] = tot;
    }

    while(m--) {
        cin >> q;
        cout << ans[q] << " ";
    }
    cout << endl;
}