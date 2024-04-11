#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct tree{
    struct edge{
        int dst; // add more info if necessary
    };

    int n;
    vector<vector<edge>> adj;
    vector<int> mark, que, parent, size, max_child;

    vector<int> rank;

    tree(int n) : n(n){
        adj = vector<vector<edge>>(n);
        mark = vector<int>(n), que = vector<int>(n);
        parent = vector<int>(n), size = vector<int>(n);
        max_child = vector<int>(n);

        rank = vector<int>(n);
    }

    void add_edge(int u, int v){
        adj[u].push_back({v});
        adj[v].push_back({u});
    }

    int centroid(int c){
        int pnt = 0, tot = 0;
        que[tot++] = c, parent[c] = -1, size[c] = 1, max_child[c] = 0;

        while (pnt < tot){
            int u = que[pnt++];
            for (auto e : adj[u]) if (e.dst != parent[u] && !mark[e.dst])
                parent[e.dst] = u, size[e.dst] = 1, max_child[e.dst] = 0, que[tot++] = e.dst;
        }

        for (int i = tot - 1; ~i; --i){
            int u = que[i];
            int bc = max(tot - size[u], max_child[u]);
            if (2 * bc <= tot) return u;
            size[parent[u]] += size[u];
            max_child[parent[u]] = max(max_child[parent[u]], size[u]);
        }

        assert(false);
        return -1;
    }

    void divide_and_conquer(int s, int r=0){
        int c = centroid(s);
        mark[c] = true;

        rank[c] = r;

        for (auto e : adj[c])
            if (!mark[e.dst])
                divide_and_conquer(e.dst, r + 1);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    tree T(n);

    for (int i = 0; i + 1 < n; ++i){
        int u, v; cin >> u >> v;
        u--; v--;

        T.add_edge(u, v);
    }

    T.divide_and_conquer(0);

    for (int i = 0; i < n; ++i)
        cout << (char)('A' + T.rank[i]) << " ";
    cout << endl;

    return 0;
}