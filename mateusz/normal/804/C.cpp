#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, m;
int size;
int color[N];
vector<int> V[N], nodes[N];
bool vis[N];

void DFS(int w) {
    vis[w] = true;
    vector<int> usedColors;
    for (int j = 0; j < nodes[w].size(); j++) {
        if (color[nodes[w][j]] != 0) {
            usedColors.push_back(color[nodes[w][j]]);
        }
    }
    sort(usedColors.begin(), usedColors.end());
    int curColor = 1;
    int ptr = 0;
    for (int j = 0; j < nodes[w].size(); j++) {
        if (color[nodes[w][j]] != 0) continue;
        while (ptr < usedColors.size() && curColor == usedColors[ptr]) {
            curColor++;
            ptr++;
        }
        color[nodes[w][j]] = curColor;
        curColor++;
    }
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            DFS(u);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &size);
        for (int j = 0; j < size; j++) {
            int x;
            scanf("%d", &x);
            nodes[i].push_back(x);
        }
        
    }
    
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    DFS(1);
    
    for (int i = 1; i <= m; i++) {
        if (color[i] == 0) color[i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = max(ans, color[i]);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) {
        printf("%d ", color[i]);
    }
    return 0;
}