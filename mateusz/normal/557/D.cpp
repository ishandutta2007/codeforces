#include <bits/stdc++.h>

using namespace std;

int DFS(int w, vector<int> *G, bool *vis, int *color) {
    vis[w] = true;
    int ret = 1;
    for (int i = 0; i < G[w].size(); i++) {
        int u = G[w][i];
        if (vis[u] == false) {
            color[u] = 1 - color[w];
            int r = DFS(u, G, vis, color);
            if (r == -1) {
                return -1;
            } else {
                ret += r;
            }
        } else if (color[w] == color[u]) {
            return -1;
        }
    }
    return ret;
}

int DFS2(int w, vector<int> *G, bool *vis, int *color) {
    vis[w] = true;
    int ret = color[w] == 0;
    for (int i = 0; i < G[w].size(); i++) {
        int u = G[w][i];
        if (vis[u] == false) {
            color[u] = 1 - color[w];
            ret += DFS2(u, G, vis, color);
        }
    }
    return ret;
}

long long getAns(vector<int> *G, int n) {
    bool vis[n + 1], vis2[n + 1];
    int color[n + 1];
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        vis2[i] = false;
        color[i] = 0;
    }
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            int black = DFS2(i, G, vis, color);
            int all = DFS(i, G, vis2, color);
            ret += (long long)black * (black - 1) / 2 + (long long)(all - black) * (all - black - 1) / 2;
        }
    }
    return ret;
}

pair<int, long long> solve(int n, int m, int *a, int *b) {
    bool vis[n + 1];
    int color[n + 1];
    vector<int> G[n + 1];
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        color[i] = 0;
    }
    vector<int> componentsSizes;
    for (int i = 0; i < m; i++) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            int r = DFS(i, G, vis, color);
            if (r == -1) {
                return make_pair(0, 1);
            }
            componentsSizes.push_back(r);
        }
    }
    sort(componentsSizes.begin(), componentsSizes.end());
    long long ans = 0;
    if (componentsSizes.back() > 2) {
        ans = getAns(G, n);
        return make_pair(1, ans);
    } else if (componentsSizes.back() == 2) {
        ans = (long long)m * (n - 2);
        return make_pair(2, ans);
    } else {
        ans = (long long)n * (n - 1) * (n - 2) / 6;
        return make_pair(3, ans);
    }
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    int a[m], b[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    pair<int, long long> ans = solve(n, m, a, b);
    printf("%d %I64d\n", ans.first, ans.second);

    return 0;
}