#include <bits/stdc++.h>

using namespace std;

const int N = 200005, M = 1e9 + 7;

int n;
int tab[N];
int vis[N];
int pot[N];

int DFS(int w) {
    if (vis[w] == 0) {
        vis[w] = 1;
    } else {
        vis[w] = 2;
    }

    int ret = 0;

    if (vis[tab[w]] == 0) {
        ret = DFS(tab[w]);
    } else if (vis[tab[w]] == 1) {
        ret = DFS(tab[w]) + 1;
    } else if (vis[tab[w]] == 2) {
        ret = 0;
    }

    vis[w] = 3;
    return ret;
}

int mul(int a, int b) {
    return (long long)a * b % M;
}

int main() {

    scanf("%d", &n);
    pot[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot[i] = pot[i - 1] * 2 % M;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    int cycleEdges = 0;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int c = DFS(i);
            cycleEdges += c;
            if (c > 0) {
                ans = mul(ans, (((pot[c] - 2) + M) % M));
            }
        }
    }

    ans = mul(ans, pot[n - cycleEdges]);

    printf("%d\n", ans);

    return 0;
}