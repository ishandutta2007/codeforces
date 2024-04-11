#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, a, b;
vector<int> V[N];
bool vis[N];
int isCat[N];

int DFS(int w, int cats, int maxCats) {

    vis[w] = true;
    if (isCat[w] == true) {
        cats++;
    } else {
        cats = 0;
    }
    maxCats = max(maxCats, cats);
    if (w != 1 && V[w].size() == 1) {
        return maxCats <= m;
    }
    int ret = 0;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (vis[u] == false) {
            ret += DFS(u, cats, maxCats);
        }
    }
    return ret;
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &isCat[i]);
    }

    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    printf("%d\n", DFS(1, 0, 0));

    return 0;
}