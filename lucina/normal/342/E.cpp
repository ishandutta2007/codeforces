#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10, inf = 1e9;
int n, m;
vector <int> a[nax];
vector <int> c[nax]; /// centroid tree
bool out[nax];
int parent[nax][18];
int timer;
int tin[nax];
int tout[nax];
int d[nax];
int centroid_par[nax];
int centroid_root ;
int ans[nax];
int sz[nax];
/// Didn't except centroid code to be this long. O_o

int dfs_sz (vector <int> * v, int nod, int pa) {
    sz[nod] = 1;

    for (int i : v[nod]) {
        if (!out[i] && i != pa)
            sz[nod] +=  dfs_sz(v, i, nod);
    }

    return sz[nod];
}

int find_centroid (vector <int> * v, int nod, int pa, int tree_sz) {

    for (int i : v[nod]) {
        if (!out[i] && i != pa && sz[i] > tree_sz / 2) {
            return find_centroid(v, i, nod, tree_sz);
        }
    }

    return nod;
}

int find_centroid (vector <int> * v, int root) {
    dfs_sz(v, root, 0);
    return find_centroid(v, root, 0, sz[root]);
}

int build_centroid_tree(vector <int> * v, int root) {
    int centroid = find_centroid(v, root);
    out[centroid] = true;

    for (int i : v[centroid]) {
        if (!out[i]) {
            int ret = build_centroid_tree(v, i);
            c[centroid].push_back(ret);
            c[ret].push_back(centroid);
            centroid_par[ret] = centroid;
        }
    }

    return centroid;
}

void dfs_lca (vector <int> * v, int nod, int pa, int dist) {

    parent[nod][0] = pa;
    tin[nod] = ++ timer;
    d[nod] = dist;

    for (int i : v[nod]) {
        if (i != pa) {
            dfs_lca(v, i, nod, dist + 1);
        }
    }

    tout[nod] = ++ timer;

}

inline bool ancestor (int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

inline int lca (int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;

    for (int i = 17 ; i >= 0 ; -- i) {
        if (!ancestor(parent[u][i], v)) {
            u = parent[u][i];
        }
    }

    return parent[u][0];
}

void build_lca () {
    dfs_lca(a, 1, 0, 0);

    for (int j = 1 ; j < 18 ; ++ j) {
        for (int i = 1 ; i <= n ; ++ i) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int dist (int u, int v) {
    int lc = lca(u, v);
    return  d[u] + d[v] - 2 * d[lc];
}

void paint (int nod) {
    int start = nod;

    do {
        ans[nod] = min(ans[nod], dist(start, nod));
        nod = centroid_par[nod];
    } while (nod > 0);

}

int find_closest (int nod) {

    int answer = inf;
    int start = nod;

    do {
        answer = min(answer, ans[nod] + dist(nod, start));
        nod = centroid_par[nod];
    } while (nod > 0);

    return answer;
}

int main () {

    tout[0] = inf;

    scanf("%d %d", &n, &m);

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    build_lca();

    centroid_root = build_centroid_tree(a, 1);

    fprintf(stderr, "ALIVE\n");
    fill(ans + 1, ans + 1 + n, inf);

    paint(1);

    while (m -- ) {
        int opt, nod;

        scanf("%d %d", &opt, &nod);

        if (opt == 1) {
            paint(nod);
        } else if (opt == 2) {
            printf("%d\n", find_closest(nod));
        } else throw;
    }
}