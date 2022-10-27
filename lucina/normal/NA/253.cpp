#include <bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

vector <int> a[nax];
int n, k, m;
int h[nax];
int parent[nax];
int deepest = -1;
int deepest_node = -1;
bool vis[nax];

void dfs (int nod, int par, int dep) {
    vis[nod] = true;
    parent[nod] = par;
    h[nod] = dep;
  //  printf("dfs nod par dep %d %d\n", nod, par, dep);

    for (int i : a[nod]) {
        if (i == par) continue;
        if (vis[i] && h[i] < h[nod]) {
            if (h[nod] - h[i] + 1 <= k) {
                printf("2\n");
                int iter = h[nod] - h[i] + 1;
                printf("%d\n", iter, nod, i);
                for (; iter > 0 ; -- iter) {
                    printf("%d ", nod);
                    nod = parent[nod];
                }
                exit(0);
            } else {
                if (dep > deepest) {
                    deepest = dep;
                    deepest_node = nod;
                }
            }
        } else if (!vis[i]){
            dfs(i, nod, dep + 1);
        }
    }
}

int deg[nax];
int dp[2][nax];

void dfs_dp (int nod, int par) {
    /**
        dp[0][nod] maximum independent set on subtree such that nod is not used yet
        dp[1][nod] maximum independent set on subtree such that nod is already used
    */

    int mx = 0;
    for (int i : a[nod]) {
        if (i != par) {
            dfs_dp(i, nod);
            dp[1][nod] += dp[0][i];
            dp[0][nod] += max(dp[1][i], dp[0][i]);
        }
    }

    dp[1][nod] ++;
}
int iter ;
void print (int x) {
    printf("%d ", x);
    -- iter;
    if (iter == 0) exit(0);
}

void try_restore (int nod, int par, int used) {
    if (used == 1) {
        print(nod);
        for (int i : a[nod]) {
            if (i != par)
                try_restore(i, nod, 0);
        }
    } else if (used == 0) {
        for (int i : a[nod]) {
            if (i != par)
                try_restore(i, nod, dp[1][i] >= dp[0][i] ? 1 : 0);
        }
    } else throw;
}

int main () {
    scanf("%d %d %d", &n, &m, &k);
    for (int j = 1 ; j <= m ; ++ j) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
        ++ deg[u];
        ++ deg[v];
    }

    dfs(1, 0, 0);

    int x = deepest_node;
    iter = (k + 1) / 2;
    if (deepest_node != -1) {
        printf("1\n");
        for (int i = 1 ; i <= iter ; ++ i) {
            printf("%d ", x);
            x = parent[parent[x]];
        }
        return 0;
    }

    printf("1\n");
    dfs_dp(1, 0);
    try_restore(1, 0, dp[1][1] >= dp[1][0] ? 1 : 0);

    assert(false);


   // fprintf(stderr, "Tree case\n");
}