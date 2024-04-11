#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int n, k;

vector<int> a[nax];
int pa[nax];
int dep[nax];
int b[nax];

void dfs_parent (int nod, int pa) {
    ::pa[nod] = pa;

    for (int i : a[nod]) {
        if (i == pa) continue;
        dep[i] = dep[nod] + 1;
        dfs_parent(i, nod);
    }
}

int sz[nax];

void dfs_sz (int nod, int pa) {
    sz[nod] = 1;
    for (int i : a[nod])
        if (i != pa) {
            dfs_sz(i, nod);
            sz[nod] += sz[i];
        }
}

int main () {
    scanf("%d %d", &n, &k);

    for (int i = 1 ; i < n;  ++ i) {
        int u, v;

        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs_parent(1, 0);
    dfs_sz(1, 0);

    for (int i = 1 ; i <= n; ++ i) {
        b[i] = dep[i] - (sz[i] - 1);
    }

    sort(b + 1, b + 1 + n);
    reverse(b + 1, b + 1 + n);

    printf("%lld\n", accumulate(b + 1, b + 1 + k, 0LL));

}
/*
    Good Luck
        -Lucina
*/