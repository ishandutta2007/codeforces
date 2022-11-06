#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int vis[N];
int tab[N];
int ans, root;

void DFS(int w) {
    vis[w] = 1;
    if (!vis[tab[w]]) {
        DFS(tab[w]);
    } else if (vis[tab[w]] == 1) {
        if (root == -1) {
            root = w;
            tab[w] = w;
        }
        if (w != root) {
            ans++;
            tab[w] = root;
        }
    }
    vis[w] = 2;
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        if (i == tab[i]) {
            root = i;
        }
    }

    if (root == 0) {
        root = -1;
        ans++;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            DFS(i);
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d ", tab[i]);
    }

    return 0;
}