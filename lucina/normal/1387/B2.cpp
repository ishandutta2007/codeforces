#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
vector <int> a[nax];
int n;
int sz[nax];
int dist[nax];
int p[nax];
int mx;
vector <int> all;
int ct = 0;
int sub[nax];
int col;

void dfs_sz (int nod, int parent, int d) {
    sz[nod] = 1;
    dist[nod] = d;
    for (int i : a[nod]) {
        if (i == parent) continue;
        dfs_sz(i, nod, d + 1);
        sz[nod] += sz[i];
    }
}

int find_centroid (int nod, int parent) {
    for (int i : a[nod]) {
        if (i == parent) continue;
        if (sz[i] > n / 2) return find_centroid(i, nod);
    }
    return nod;
}

void add (int nod, int parent) {
    all.push_back(nod);
    sub[nod] = col;
    ++ ct;
    for (int i : a[nod]) {
        if (i != parent)
            add(i, nod);
    }
}

int main () {
    scanf("%d", &n);


    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs_sz(1, 0, 0);
    int root = find_centroid(1, 0);
    dfs_sz(root, 0, 0);

    long long ans = 0;

    for (int i = 1 ; i <= n ; ++ i)
        ans += 2 * dist[i];

    printf("%lld\n", ans);

    int mx = 1;
    all.push_back(root);

    for (int i : a[root]) {
        ++ col;
        ct = 0;
        add(i, root);
        mx = max(mx, ct);
    }

    assert(all.size() == n);
    for (int i = 0 ; i < int(all.size()) ; ++ i) {
        p[all[i]] = all[(i + n / 2) % n];
    }

    assert(mx <= n / 2);

    long long ck = 0;

    for (int i = 1 ; i <= n ; ++ i) {
      //  assert(sub[i] != sub[p[i]]);
        printf("%d ", p[i]);
        ck += dist[i] + dist[p[i]];
        assert(p[i] != i);
        assert(p[i] > 0);
    }

    assert(ck == ans);
}