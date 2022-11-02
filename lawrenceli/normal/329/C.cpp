#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 100010;

int n, m;
set<int> adj[MAXN];
int perm[MAXN];

bool good() {
    if (n==2 && m==2) return 0;
    for (int i=0; i<m; i++) {
        if (adj[perm[i]].count(perm[(i+1)%n])) return 0;
    }
    return 1;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    srand(0);
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int i=0; i<n; i++) perm[i] = i+1;
    if (n<=7) {
        do {
            if (good()) {
                for (int i=0; i<m; i++) printf("%d %d\n", perm[i], perm[(i+1)%n]);
                return 0;
            }
        } while (next_permutation(perm, perm+n));
    }
    else {
        for (int i=0; i<=2000000/n; i++) {
            random_shuffle(perm, perm+n);
            if (good()) {
                for (int j=0; j<m; j++) printf("%d %d\n", perm[j], perm[(j+1)%n]);
                return 0;
            }
        }
    }
    printf("-1\n");
}