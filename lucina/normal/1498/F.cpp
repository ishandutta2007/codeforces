#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
const int K = 42;
int n, k;
int a[nax];
int b[nax][K], c[nax][K];
vector <int> g[nax];

/**
     c[x][w] is xor_sum of all node int subtree x such that
     height % k == w
*/

void dfs(int v, int parent) {
    b[v][0] = a[v];
    for (int to : g[v]) {
        if (to == parent) continue;
        dfs(to, v);
        for (int i = 0 ; i < k ; ++ i) {
            b[v][(i + 1) % k] ^= b[to][i];
        }
    }
}

void dfs_reroot(int v, int parent) {

    for (int to : g[v]) {
        if (to == parent) continue;

        for (int i = 0 ; i < k ; ++ i) {
            int x = b[v][i] ^ c[v][i];
            x ^= b[to][(i + k - 1) % k];
            c[to][(i + 1) % k] = x;
        }
        dfs_reroot(to, v);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    k <<= 1;
    for (int i = 1, u, v ; i < n ; ++ i) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    dfs(1, 0);
    dfs_reroot(1, 0);

    for (int i = 1 ; i <= n ; ++ i) {
        int x = 0;
        for (int j = k / 2 ; j < k ; ++ j) {
            x ^= b[i][j] ^ c[i][j];
        }
        x = min(x, 1);
        printf("%d ", x);
    }
    puts("");
}